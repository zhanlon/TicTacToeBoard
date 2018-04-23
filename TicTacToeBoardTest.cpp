/**
 * Unit Tests for TicTacToeBoard
**/

#include <gtest/gtest.h>
#include "TicTacToeBoard.h"
 
class TicTacToeBoardTest : public ::testing::Test
{
	protected:
		TicTacToeBoardTest(){} //constructor runs before each test
		virtual ~TicTacToeBoardTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

/* EXAMPLE TEST FORMAT
TEST(TicTacToeBoardTest, sanityCheck)
{
	ASSERT_TRUE(true);
}
*/

TEST(TicTacToeBoardTest, smokeTest)
{
	TicTacToeBoard myBoard;
	ASSERT_EQ(myBoard.getTurn(), X);
}

TEST(TicTacToeBoardTest, toggleTurnTest )
{
	TicTacToeBoard myBoard;
	myBoard.toggleTurn();
	ASSERT_EQ(myBoard.getTurn(), O);
}

TEST(TicTacToeBoardTest, placePieceOnBlank)
{
	TicTacToeBoard myBoard;
	myBoard.placePiece(0,0);
	ASSERT_EQ(myBoard.getPiece(0, 0), X);
}

TEST(TicTacToeBoardTest, placePieceOutsideBoard)
{
	TicTacToeBoard myBoard;
	ASSERT_EQ(myBoard.placePiece(0, 4), Invalid);
}

TEST(TicTacToeBoardTest, placePieceOnTakenSpot)
{
	TicTacToeBoard myBoard;
	myBoard.placePiece(0, 0);
	ASSERT_EQ(myBoard.placePiece(0, 0), X);
}

TEST(TicTacToeBoardTest, getPieceTestX )
{
	TicTacToeBoard myBoard;
	myBoard.placePiece(0, 0);
	ASSERT_EQ(myBoard.getPiece(0, 0), X);
}

TEST(TicTacToeBoardTest, getPieceTestO )
{
	TicTacToeBoard myBoard;
	myBoard.placePiece(0, 0);
	myBoard.placePiece(0, 1);
	ASSERT_EQ(myBoard.getPiece(0, 1), O);
}

TEST(TicTacToeBoardTest, getPieceTestBlank )
{
	TicTacToeBoard myBoard;
	ASSERT_EQ(myBoard.getPiece(0, 0), Blank);
}

TEST(TicTacToeBoardTest, getPieceInvalid)
{
	TicTacToeBoard myBoard;
	ASSERT_EQ(myBoard.getPiece(4, 0), Invalid);
}

TEST(TicTacToeBoardTest, getWinnerdiagX )
{
	TicTacToeBoard myBoard;
	myBoard.placePiece(0,0);
	myBoard.placePiece(1,0);
	myBoard.placePiece(1,1);
	myBoard.placePiece(0,2);
	myBoard.placePiece(2,2);
	ASSERT_EQ(myBoard.getWinner(), X);
}

TEST(TicTacToeBoardTest, getWinnerVertO)
{
	TicTacToeBoard myBoard;
	myBoard.placePiece(1,1);
	myBoard.placePiece(0,0);
	myBoard.placePiece(2,1);
	myBoard.placePiece(0,1);
	myBoard.placePiece(2,2);
	myBoard.placePiece(0,2);
	ASSERT_EQ(myBoard.getWinner(), O);
}

TEST(TicTacToeBoardTest, getWinnerHorizO)
{
	TicTacToeBoard myBoard;
	myBoard.placePiece(1,1);
	myBoard.placePiece(0,0);
	myBoard.placePiece(2,1);
	myBoard.placePiece(1,0);
	myBoard.placePiece(2,2);
	myBoard.placePiece(2,0);
	ASSERT_EQ(myBoard.getWinner(), O);
}

TEST(TicTacToeBoardTest, getWinnerNotDone)
{
	TicTacToeBoard myBoard;
	myBoard.placePiece(0,0);
	myBoard.placePiece(1,1);
	myBoard.placePiece(0,2);
	ASSERT_EQ(myBoard.getWinner(), Invalid);
}

TEST(TicTacToeBoardTest, getWinnerCatsGame)
{
	TicTacToeBoard myBoard;
	myBoard.fillBoardCatsGame();
	// myBoard.placePiece(0,0);
	// myBoard.placePiece(1,1);
	// myBoard.placePiece(0,2);
	// myBoard.placePiece(0,1);
	// myBoard.placePiece(2,0);
	// myBoard.placePiece(1,0);
	// myBoard.placePiece(1,2);
	// myBoard.placePiece(2,2);
	// myBoard.placePiece(2,1);
	ASSERT_EQ(myBoard.getWinner(), Blank);
}