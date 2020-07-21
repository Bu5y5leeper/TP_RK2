// ===========================================================================
// FileComponent.h
// ===========================================================================

class FileComponent {
public:
    virtual ~FileComponent() = default;
    virtual void display(const std::string&) const = 0;
};

// ===========================================================================
// End-of-File
// ===========================================================================