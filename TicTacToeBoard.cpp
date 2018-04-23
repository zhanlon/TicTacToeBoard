#include "TicTacToeBoard.h"
/**
 * Class for representing a 3x3 Tic-Tac-Toe game board, using the Piece enum
 * to represent the spaces on the board.
**/

//Constructor sets an empty board and specifies it is X's turn first
TicTacToeBoard::TicTacToeBoard()
{
  turn = X;
  for(int i=0; i<BOARDSIZE; i++)
    for(int j=0; j<BOARDSIZE; j++)
      board[i][j] = Blank;
}

/**
 * Switches turn member variable to represent whether it's X's or O's turn
 * and returns whose turn it is
**/
Piece TicTacToeBoard::toggleTurn()
{
    if(turn == X)
    {
      turn = O;
      return O;
    }
    else{
      turn = X;
      return X;
    }
}

/**
 * Places the piece of the current turn on the board, returns what
 * piece is placed, and toggles which Piece's turn it is. placePiece does 
 * NOT allow to place a piece in a location where there is already a piece.
 * In that case, placePiece just returns what is already at that location. 
 * Out of bounds coordinates return the Piece Invalid value. When the game
 * is over, no more pieces can be placed so attempting to place a piece
 * should neither change the board nor change whose turn it is.
**/ 
Piece TicTacToeBoard::placePiece(int row, int column)
{

      if(row <= 2 && row >= 0 &&  column <= 2 && column >= 0 )//in bounds?
      {
          if(board[row][column] == Blank)//is spot open?
          {
            board[row][column] = turn;
            toggleTurn();
            return board[row][column];
    
          }
          else//spot is already taken, so return value
          {
            return board[row][column];
          }
      }
      else//if spot not valid, return Invalid
      return Invalid;
}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
**/
Piece TicTacToeBoard::getPiece(int row, int column) //Done
{
  if(board[row][column] == X)
  {
  return X;
  }
  else if(board[row][column] == O)
  {
  return O;
  }
  else if(board[row][column] == Blank)
  {
    return Blank;
  }
  else return Invalid;
}

/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won.
**/
Piece TicTacToeBoard::getWinner()//Done, brute forced it, but it's done.
{
  //vert, then horiz, then diag check
  if((board[0][0] == X && board[0][1] == X && board[0][2] == X) || (board[1][0] == X && board[1][1] == X && board[1][2] == X) || (board[2][0] == X && board[2][1] == X && board[2][2] == X)
    ||(board[0][0] == X && board[1][0] == X && board[2][0] == X) || (board[0][1] == X && board[1][1] == X && board[2][1] == X) || (board[0][2] == X && board[1][2] == X && board[2][2] == X)
    ||(board[0][0] == X && board[1][1] == X && board[2][2] == X) || (board[2][0] == X && board[1][1] == X && board[0][2] == X))
   {
     return X;
   }
  
  if((board[0][0] == O && board[0][1] == O && board[0][2] == O) || (board[1][0] == O && board[1][1] == O && board[1][2] == O) || (board[2][0] == O && board[2][1] == O && board[2][2] == O)
    ||(board[0][0] == O && board[1][0] == O && board[2][0] == O) || (board[0][1] == O && board[1][1] == O && board[2][1] == O) || (board[0][2] == O && board[1][2] == O && board[2][2] == O)
    ||(board[0][0] == O && board[1][1] == O && board[2][2] == O) || (board[2][0] == O && board[1][1] == O && board[0][2] == O))
   {
     return O;
   }
   for(int i =0; i < BOARDSIZE; i++)
   {
      for(int j = 0; j < BOARDSIZE; j++)
      {
        if (board[i][j] == Blank)
        {
          return Invalid;
        }
      }
   }
  return Blank;
  
  
  // //checking row, column, diag
  // for(int columnrow = 0; columnrow < BOARDSIZE; columnrow++)
  // {
  //     //column win for X
  //     for(int i = 0; i < BOARDSIZE; i++){
  //         if(board[columnrow][i] != X)
  //             break;
  //         else{
  //             return X;
  //         }
  //     }
    
  //     //row win for X
  //     for(int i = 0; i < BOARDSIZE; i++){
  //         if(board[i][columnrow] != X)
  //             break;
  //         else{
  //             return X;
  //         }
  //     }
      
  //     //diag win for X
  //     if((board[0][0] == X && board[1][1] == X && board[2][2] == X) || (board[2][0] == X && board[1][1] == X && board[0][2] == X))
  //     {
  //       return X;
  //     }
      
  //   //column win for O
  //     for(int i = 0; i < BOARDSIZE; i++){
  //         if(board[columnrow][i] != O)
  //             break;
  //         else{
  //               return O;
  //         }
  //     }
    
  //     //row win for O
  //     for(int i = 0; i < BOARDSIZE; i++){
  //         if(board[i][columnrow] != O)
  //             break;
  //         else{
  //             return O;
  //         }
  //     }
  //     //diagonal win for O
  //     if((board[0][0] == O && board[1][1] == O && board[2][2] == O) || (board[2][0] == O && board[1][1] == O && board[0][2] == O))
  //     {
  //       return O;
  //     }
  // }
   
  // //not full, no one has won -> game not over yet.
  // for(int i = 0; i < BOARDSIZE; i++){
  //     for(int j = 0; j < BOARDSIZE; j++){
  //         if(board[i][j] == Blank)
  //         {
  //           return Invalid;
  //         }
  //     }
  // }
  // return Blank; //full but no one has won.
  
      

}

Piece TicTacToeBoard::getTurn()
{
  if(turn == O)
  return O;
  else return X;
}

void TicTacToeBoard::fillBoardCatsGame()
{
  
  board[0][0] = O;
  board[0][1] = X;
  board[0][2] = O;
  board[1][0] = X;
  board[1][1] = O;
  board[1][2] = X;
  board[2][0] = X;
  board[2][1] = O;
  board[2][2] = X;
  
  
}