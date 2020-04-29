#include "Piezas.h"
#include <vector>
/** CLASS Piezas
 * Class for representing a Piezas vertical board, which is roughly based
 * on the game "Connect Four" where pieces are placed in a column and 
 * fall to the bottom of the column, or on top of other pieces already in
 * that column. For an illustration of the board, see:
 *  https://en.wikipedia.org/wiki/Connect_Four
 *
 * Board coordinates [row,col] should match with:
 * [2,0][2,1][2,2][2,3]
 * [1,0][1,1][1,2][1,3]
 * [0,0][0,1][0,2][0,3]
 * So that a piece dropped in column 2 should take [0,2] and the next one
 * dropped in column 2 should take [1,2].
 **/


/**
 * Constructor sets an empty board (default 3 rows, 4 columns) and 
 * specifies it is X's turn first
 **/
Piezas::Piezas()
{
  board.resize(3); // Rows
  for(unsigned int i = 0; i < board.size(); i++)
  {
    board[i].resize(4); // Columns
    for(unsigned int j = 0; j < board[i].size(); j++)
    {
      board[i][j] = Blank; //Initialize all members to blank
    }
  }
  turn = X;
}

/**
 * Resets each board location to the Blank Piece value, with a board of the
 * same size as previously specified
 **/
void Piezas::reset()
{
  for(unsigned int i=0; i < board.size(); i++)
  {
    for(unsigned int j=0; j < board.size(); j++)
    {
      board[i][j] = Blank; // Reset all locations to blank
    }
  }
}

/**
 * Places a piece of the current turn on the board, returns what
 * piece is placed, and toggles which Piece's turn it is. dropPiece does 
 * NOT allow to place a piece in a location where a column is full.
 * In that case, placePiece returns Piece Blank value 
 * Out of bounds coordinates return the Piece Invalid value
 * Trying to drop a piece where it cannot be placed loses the player's turn
 **/ 
Piece Piezas::dropPiece(int column)
{
  Piece curTurn = turn; //Save piece to put on board
  turn = (turn == X) ? O : X; // Toggle who's turn it is

  //Check out of bounds
  if((unsigned int)column >= board[0].size())
    return Invalid;

  //Check full column
  if(board[board.size()-1][column] != Blank)
    return Blank;

      //insert piece
      for(unsigned int i=0; i < board.size(); i++)
      {
        if(board[i][column] == Blank)
        {
          board[i][column] = curTurn;
          return curTurn;
        }
      }
  return Blank; //Should never get here, but if it did, it's an error
}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
 **/
Piece Piezas::pieceAt(int row, int column)
{
  //Check out of bounds, return Invalid if so
  if((unsigned int)row >= board.size() || (unsigned int)column >= board[0].size())
    return Invalid;

  return board[row][column];
}

/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won ("tie").
 * For a game to be over, all locations on the board must be filled with X's 
 * and O's (i.e. no remaining Blank spaces). The winner is which player has
 * the most adjacent pieces in a single line. Lines can go either vertically
 * or horizontally. If both X's and O's have the same max number of pieces in a
 * line, it is a tie.
 **/
Piece Piezas::gameState()
{
  //Holds absolute max
  int max_x=0;
  int max_o=0;

  //Holds current calculations
  int cur_x=0;
  int cur_o=0;

  //Check horizontal
  for(unsigned int i=0; i < board.size(); i++)
  {
    for(unsigned int j=0; j < board[i].size(); j++)
    {
      //If a tile is blank, game isn't over
      if(board[i][j] == Blank)
        return Invalid;
      else if(board[i][j] == X)
      {
        cur_o=0; // Reset current O's
        cur_x++; // Update X streak
        if(cur_x > max_x)
          max_x = cur_x;
      }
      else if(board[i][j] == O)
      {
        cur_x=0; // Reset current X's
        cur_o++; // Update O streak
        if(cur_o > max_o)
          max_o = cur_o;
      }
    }
  }

  //Check Vertical
  for(unsigned int j=0; j < board[0].size(); j++) // Relies upon the game board being square
  {
    for(unsigned int i=0; i < board.size(); i++)
    {
      //If a tile is blank, game isn't over
      if(board[i][j] == Blank)
        return Invalid;
      else if(board[i][j] == X)
      {
        cur_o=0; // Reset current O's
        cur_x++; // Update X streak
        if(cur_x > max_x)
          max_x = cur_x;
      }
      else if(board[i][j] == O)
      {
        cur_x=0; // Reset current X's
        cur_o++; // Update O streak
        if(cur_o > max_o)
          max_o = cur_o;
      }
    }
  }
  //Return winner, blank if tie
  if(max_x == max_o)
    return Blank;
  return (max_x > max_o) ? X : O; // Max of the two
}
