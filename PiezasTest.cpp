/**
 * Unit Tests for Piezas
**/

#include <gtest/gtest.h>
#include "Piezas.h"
 
class PiezasTest : public ::testing::Test
{
	protected:
		PiezasTest(){} //constructor runs before each test
		virtual ~PiezasTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

//SANITY CHECK
TEST(PiezasTest, sanityCheck)
{
	ASSERT_TRUE(true);
}

//TESTS FOR DROP PIECE

// Drop an X
TEST(PiezasTest, drop_piece_x)
{
  Piezas board;
  Piece ret;
  ret = board.dropPiece(0);
  ASSERT_EQ(ret, X);
}

// Drop a Y
TEST(PiezasTest, drop_piece_y)
{
  Piezas board;
  Piece ret;
  board.dropPiece(0);
  ret = board.dropPiece(0);
  ASSERT_EQ(ret, Y);
}

// Drop last X in column
TEST(PiezasTest, drop_piece_last_x)
{
  Piezas board;
  Piece ret;
  board.dropPiece(0);
  board.dropPiece(0);
  ret = board.dropPiece(0);
  ASSERT_EQ(ret, X);
}

// Invalid Drop
TEST(PiezasTest, drop_piece_invalid_column)
{
  Piezas board;
  Piece ret;
  board.dropPiece(0);
  board.dropPiece(0);
  board.dropPiece(0);
  ret = board.dropPiece(0);
  ASSERT_EQ(ret, Invalid);
}
