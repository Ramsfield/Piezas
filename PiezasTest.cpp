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

/*********************************************************************
 *********************************************************************
 *****************SIMPLE TESTS FOR CONSTRUCTOR************************
 *********************************************************************
 *********************************************************************/
TEST(PiezasTest, ensure_4_x_3_blank)
{
  Piezas board;
  for(int i=0; i < 3; i++)
  {
    for(int j=0; j < 4; j++)
    {
      ASSERT_EQ(board.pieceAt(i,j), Blank);
    }
  }
}

/*********************************************************************
 *********************************************************************
 *****************SIMPLE TESTS FOR DROP PIECE*************************
 *********************************************************************
 *********************************************************************/
// Drop an X
TEST(PiezasTest, drop_piece_x)
{
  Piezas board;
  Piece ret;
  ret = board.dropPiece(0);
  ASSERT_EQ(ret, X);
}

// Drop a O
TEST(PiezasTest, drop_piece_o)
{
  Piezas board;
  Piece ret;
  board.dropPiece(0);
  ret = board.dropPiece(0);
  ASSERT_EQ(ret, O);
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
  ASSERT_EQ(ret, Blank);
}

TEST(PiezasTest, drop_piece_out_of_bounds)
{
  Piezas board;
  Piece ret;
  ret = board.dropPiece(7);
  ASSERT_EQ(ret, Invalid);
}

TEST(PiezasTest, drop_piece_loss_of_turn)
{
  Piezas board;
  Piece ret;
  board.dropPiece(7);
  ret = board.dropPiece(0);
  ASSERT_EQ(ret, O);
}

/*********************************************************************
 *********************************************************************
 *****************SIMPLE TESTS FOR PIECE AT****************************
 *********************************************************************
 *********************************************************************/

TEST(PiezasTest, blank_piece_start)
{
  Piezas board;
  ASSERT_EQ(board.pieceAt(0,0), Blank);
}

TEST(PiezasTest, x_at)
{
  Piezas board;
  board.dropPiece(0);
  ASSERT_EQ(board.pieceAt(0,0), X);
}

TEST(PiezasTest, o_at)
{
  Piezas board;
  board.dropPiece(0);
  board.dropPiece(0);
  ASSERT_EQ(board.pieceAt(1,0), O);
}

TEST(PiezasTest, out_of_bounds)
{
  Piezas board;
  ASSERT_EQ(board.pieceAt(-1,-1), Invalid);
}

TEST(PiezasTest, out_of_bounds_max)
{
  Piezas board;
  ASSERT_EQ(board.pieceAt(7,7), Invalid);
}

/*********************************************************************
 *********************************************************************
 *****************SIMPLE TESTS FOR RESET****************************
 *********************************************************************
 *********************************************************************/

TEST(PiezasTest, reset_simple)
{
  Piezas board;
  board.dropPiece(0);
  board.dropPiece(0);
  board.dropPiece(0);
  board.dropPiece(1);
  board.dropPiece(1);
  board.dropPiece(1);
  board.dropPiece(2);
  board.dropPiece(2);
  board.dropPiece(2);
  board.dropPiece(3);
  board.dropPiece(3);
  board.dropPiece(3);
  board.dropPiece(4);
  board.dropPiece(4);
  board.dropPiece(4);
  board.reset();
  for(unsigned int i=0; i < 3; i++)
  {
    for(unsigned int j=0; j < 4; j++)
    {
      ASSERT_EQ(board.pieceAt(i,j), Blank);
    }
  }
}

/*********************************************************************
 *********************************************************************
 *****************SIMPLE TESTS FOR GAMESTATE****************************
 *********************************************************************
 *********************************************************************/

TEST(PiezasTest, gamestate_tie)
{
  Piezas board;
  board.dropPiece(0);
  board.dropPiece(0);
  board.dropPiece(0);
  board.dropPiece(1);
  board.dropPiece(1);
  board.dropPiece(1);
  board.dropPiece(2);
  board.dropPiece(2);
  board.dropPiece(2);
  board.dropPiece(3);
  board.dropPiece(3);
  board.dropPiece(3);
  board.dropPiece(4);
  board.dropPiece(4);
  board.dropPiece(4);
  ASSERT_EQ(board.gameState(), Blank);
}

TEST(PiezasTest, gamestate_x)
{
  Piezas board;
  board.dropPiece(0);
  board.dropPiece(0);
  board.dropPiece(1);
  board.dropPiece(0);
  board.dropPiece(2);
  board.dropPiece(0);
  board.dropPiece(3);
  board.dropPiece(0);
  board.dropPiece(1);
  board.dropPiece(0);
  board.dropPiece(2);
  board.dropPiece(0);
  board.dropPiece(3);
  board.dropPiece(0);
  board.dropPiece(1);
  board.dropPiece(0);
  board.dropPiece(2);
  board.dropPiece(0);
  board.dropPiece(3);
  board.dropPiece(0);

  ASSERT_EQ(board.gameState(), X);
}

TEST(PiezasTest, gamestate_o)
{
  Piezas board;
  board.dropPiece(0);
  board.dropPiece(0);
  board.dropPiece(0);
  board.dropPiece(1);
  board.dropPiece(0);
  board.dropPiece(2);
  board.dropPiece(0);
  board.dropPiece(3);
  board.dropPiece(0);
  board.dropPiece(1);
  board.dropPiece(0);
  board.dropPiece(2);
  board.dropPiece(0);
  board.dropPiece(3);
  board.dropPiece(0);
  board.dropPiece(1);
  board.dropPiece(0);
  board.dropPiece(2);
  board.dropPiece(0);
  board.dropPiece(3);

  ASSERT_EQ(board.gameState(), O);
}

TEST(PiezasTest, gamestate_incomplete)
{
  Piezas board;
  board.dropPiece(0);
  board.dropPiece(0);
  board.dropPiece(1);
  board.dropPiece(0);
  board.dropPiece(2);
  board.dropPiece(0);
  board.dropPiece(3);
  board.dropPiece(0);
  board.dropPiece(0);
  board.dropPiece(2);
  board.dropPiece(0);
  board.dropPiece(0);
  board.dropPiece(1);
  board.dropPiece(0);
  board.dropPiece(2);
  board.dropPiece(0);

  ASSERT_EQ(board.gameState(), Invalid);
}
