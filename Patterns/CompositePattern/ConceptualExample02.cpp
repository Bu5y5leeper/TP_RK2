// ===========================================================================
// ConceptualExample02.cpp // Composite Pattern
// ===========================================================================

#include <iostream>
#include <vector>
#include <string>
#include <memory>

namespace CompositePatternSmartPointer {
    /**
     * The base Component class declares common operations for both
     * simple and complex objects of a composition.
     */
    class Component {

    protected:
        std::shared_ptr<Component> m_parent;

    public:
        Component() : m_parent(nullptr) {}
        virtual ~Component() {}

        /**
         * Optionally, the 'Component' class can declare an interface for setting and
         * accessing a parent of the component in a tree structure.
         * It can also provide some default implementation for these methods.
         */
        void setParent(std::shared_ptr<Component> parent) { m_parent = parent; }
        std::shared_ptr<Component> getParent() const { return m_parent; }

        /**
         * In some cases, it would be beneficial to define the child-management
         * operations right in the base Component class. This way, you won't need to
         * expose any concrete component classes to the client code, even during the
         * object tree assembly. The downside is that these methods will be empty for
         * the leaf-level components.
         */
        virtual void add(std::shared_ptr<Component> component) {}
        virtual void remove(std::shared_ptr<Component> component) {}

        /**
         * You can provide a method that lets the client code figure out whether
         * a component can bear children.
         */
        virtual bool isComposite() const { return false; }

        /**
         * The base Component may implement some default behavior or leave it to
         * concrete classes (by declaring the method containing the behavior as
         * "abstract").
         */
        virtual std::string operation() const = 0;
    };

    /**
     * The Leaf class represents the end objects of a composition.
     * A leaf can't have any children.
     *
     * Usually, it's the Leaf objects that do the actual work, whereas Composite
     * objects only delegate to their sub-components.
     */
    class Leaf : public Component {
    public:
        std::string operation() const override {
            return "Leaf";
        }
    };

    /**
     * The Composite class represents the complex components that may have children.
     * Usually, the Composite objects delegate the actual work to their children and
     * then "sum-up" the result.
     */
    class Composite : public Component, public std::enable_shared_from_this<Composite> {

    protected:
        std::vector<std::weak_ptr<Component>> m_children;

    public:
        virtual ~Composite() {
            m_children.clear();
        }

        /**
         * A composite object can add or remove other components (both simple or
         * complex) to or from its child list.
         */
        void add(std::shared_ptr<Component> component) {
            std::weak_ptr<Component> wcomp = component;
            m_children.push_back(wcomp);
            component->setParent(shared_from_this());
        }

        /**
         * Note: list stores 'std::weak_ptr' objects
         */
        void remove(std::shared_ptr<Component> component) {
            component->setParent(nullptr);
        }

        bool isComposite() const override {
            return true;
        }

        /**
         * The Composite executes its primary logic in a particular way. It traverses
         * recursively through all its children, collecting and summing their results.
         * Since the composite's children pass these calls to their children and so
         * forth, the whole object tree is traversed as a result.
         */
        std::string operation() const override {
            std::string result;

            // note: using simple 'old-fashioned' for-loop here - std::weak_ptr doesn't has
            // a comparison operator (!), therefore modern style loops don't work
            for (int i = 0; i < m_children.size(); ++i) {
                std::weak_ptr<Component> wcomp = m_children[i];
                std::shared_ptr<Component> comp = wcomp.lock();

                if (i == m_children.size() - 1) {
                    result = result + comp->operation();
                }
                else {
                    result = result + comp->operation() + "+";
                }
            }

            return "Branch(" + result + ")";
        }
    };


    /**
     * The client code works with all of the components via the base interface.
     */
    void clientCode(std::shared_ptr<Component> component) {
        std::cout << "Result: " << component->operation();
    }

    /**
     * Due to the fact that the child-management operations are declared in the
     * base Component class, the client code can work with any component, simple or
     * complex, without depending on their concrete classes.
     */
    void clientCode2(std::shared_ptr<Component> component1, std::shared_ptr<Component> component2) {
        if (component1->isComposite()) {
            component1->add(component2);
        }
        std::cout << "Result: " << component1->operation();
    }
}

void test_conceptual_example_02() {

    using namespace CompositePatternSmartPointer;

    std::shared_ptr<Component> simple = std::make_shared<Leaf>();
    std::cout << "Client: I've got a simple component:\n";
    clientCode(simple);
    std::cout << std::endl << std::endl;

    /**
     * ...as well as the complex composites.
     */

    std::shared_ptr<Component> tree = std::make_shared<Composite>();
    std::shared_ptr<Component> branch1 = std::make_shared<Composite>();
    std::shared_ptr<Component> leaf_1 = std::make_shared<Leaf>();
    std::shared_ptr<Component> leaf_2 = std::make_shared<Leaf>();
    std::shared_ptr<Component> leaf_3 = std::make_shared<Leaf>();

    branch1->add(leaf_1);
    branch1->add(leaf_2);

    std::shared_ptr<Component> branch2 = std::make_shared<Composite>();

    branch2->add(leaf_3);
    tree->add(branch1);
    tree->add(branch2);
    std::cout << "Client: Now I've got a composite tree:\n";
    clientCode(tree);
    std::cout << std::endl << std::endl;

    std::cout << "Client: I don't need to check the components classes even when managing the tree:\n";
    clientCode2(tree, simple);
    std::cout << std::endl;
}

// ===========================================================================
// End-of-File
// ===========================================================================
