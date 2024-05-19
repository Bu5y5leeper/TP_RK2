// ===========================================================================
// Test.cpp // Prototype Pattern
// ===========================================================================

#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <gtest/gtest.h>
#include "ConceptualExample01.hpp"
#include "ConceptualExample02.hpp"
//#include <crtdbg.h>




TEST(ConceptualEx1, TEST_1) {

	using namespace ConceptualExample01;

	Prototype* original{ new ConcretePrototype { 123 } };

	Prototype* copy{ original->clone() };

    EXPECT_EQ(original->getId(), copy->getId());

    delete copy;
	delete original;
}

TEST(ConceptualEx1, TEST_2) {
	using namespace ConceptualExample01;

    Prototype* prototype{ new ConcretePrototype(123) };
        
    Prototype* clone{  prototype->clone() };

    EXPECT_EQ(prototype->getId(), clone->getId());

    clone->setId(456);

    EXPECT_NE(prototype->getId(), clone->getId());

    delete prototype;
    delete clone;
}

TEST(ConceptualEx1, TEST_3) {
	using namespace ConceptualExample02;

    std::shared_ptr<Prototype> prototype {
        std::make_shared<ConcretePrototype>(123) 
    };

    std::shared_ptr<Prototype> clone { 
        prototype->clone() 
    };

    EXPECT_EQ(prototype->getId(), clone->getId());

    clone->setId(456);

    EXPECT_NE(prototype->getId(), clone->getId());
}

TEST(ConceptualEx2, TEST_1) {
	using namespace ExamplesPrototypePattern;

    King king;
    EXPECT_EQ("King", king.name());
}

TEST(ConceptualEx2, TEST_2) {
	using namespace ExamplesPrototypePattern;

    GameBoard board;

    board.at(0, 0) = std::make_unique<King>();
    board.at(0, 1) = std::make_unique<Pawn>();
    board.at(1, 0) = std::make_unique<Pawn>();
    board.at(1, 1) = std::make_unique<Rook>();

    EXPECT_EQ(board.at(0, 0)->name(), "King");
    EXPECT_EQ(board.at(0, 1)->name(), "Pawn");
    EXPECT_EQ(board.at(1, 0)->name(), "Pawn");
    EXPECT_EQ(board.at(1, 1)->name(), "Rook");

    // assignment
    GameBoard boardCopy;
    boardCopy = board;
    EXPECT_EQ(boardCopy.at(0, 0)->name(), "King");
    EXPECT_EQ(boardCopy.at(0, 1)->name(), "Pawn");
    EXPECT_EQ(boardCopy.at(1, 0)->name(), "Pawn");
    EXPECT_EQ(boardCopy.at(1, 1)->name(), "Rook");

    // copy c'tor
    GameBoard secondBoardCopy{ board };
    EXPECT_EQ(secondBoardCopy.at(0, 0)->name(), "King");
    EXPECT_EQ(secondBoardCopy.at(0, 1)->name(), "Pawn");
    EXPECT_EQ(secondBoardCopy.at(1, 0)->name(), "Pawn");
    EXPECT_EQ(secondBoardCopy.at(1, 1)->name(), "Rook");
}

// ===========================================================================
// End-of-File
// ===========================================================================
