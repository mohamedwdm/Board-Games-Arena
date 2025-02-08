#include <bits/stdc++.h>
#include "../include/BoardGame_Classes.hpp"
using namespace std;

// Set the board
X_O_Board::X_O_Board()
{
   n_rows = n_cols = 3;
   board = new char *[n_rows];
   for (int i = 0; i < n_rows; i++)
   {
      board[i] = new char[n_cols];
      for (int j = 0; j < n_cols; j++)
         board[i][j] = 0;
   }
}

// Return true  if move is valid and put it on board
// within board boundaries in empty cell
// Return false otherwise
bool X_O_Board::update_board(int x, int y, char mark)
{
   // Only update if move is valid
   if (!(x < 0 || x > 2 || y < 0 || y > 2) && (board[x][y] == 0))
   {
      board[x][y] = toupper(mark);
      n_moves++;
      return true;
   }
   else
      return false;
}

// Display the board and the pieces on it
void X_O_Board::display_board()
{
   for (int i : {0, 1, 2})
   {
      cout << "\n| ";
      for (int j : {0, 1, 2})
      {
         cout << "(" << i << "," << j << ")";
         cout << setw(2) << board[i][j] << " |";
      }
      cout << "\n-----------------------------";
   }
   cout << endl;
}

// Returns true if there is any winner
// either X or O
// Written in a complex way. DO NOT DO LIKE THIS.
bool X_O_Board::is_winner()
{
   char row_win[3], col_win[3], diag_win[2];
   for (int i : {0, 1, 2})
   {
      row_win[i] = board[i][0] & board[i][1] & board[i][2];
      col_win[i] = board[0][i] & board[1][i] & board[2][i];
   }
   diag_win[0] = board[0][0] & board[1][1] & board[2][2];
   diag_win[1] = board[2][0] & board[1][1] & board[0][2];

   for (int i : {0, 1, 2})
   {
      if ((row_win[i] && (row_win[i] == board[i][0])) ||
          (col_win[i] && (col_win[i] == board[0][i])))
      {
         return true;
      }
   }
   if ((diag_win[0] && diag_win[0] == board[1][1]) ||
       (diag_win[1] && diag_win[1] == board[1][1]))
   {
      return true;
   }
   return false;
}

// Return true if 9 moves are done and no winner
bool X_O_Board::is_draw()
{
   return (n_moves == 9 && !is_winner());
}

bool X_O_Board::game_is_over()
{
   return n_moves >= 9;
}

// Pyramid Board Implementation
// Set the board
X_O_PyramidBoard::X_O_PyramidBoard()
{
   n_rows = 3;
   n_cols = 5;
   board = new char *[n_rows];
   for (int i = 0; i < n_rows; i++)
   {
      board[i] = new char[n_cols];
      for (int j = 0; j < n_cols; j++)
      {
         // Set the elements in the pyramid shape
         if (j >= n_cols / 2 - i && j <= n_cols / 2 + i)
         {
            board[i][j] = 0;
         }
         else
         {
            board[i][j] = 1;
         }
      }
   }
}

// Return true  if move is valid and put it on board
// within board boundaries in empty cell
// Return false otherwise
bool X_O_PyramidBoard::update_board(int x, int y, char mark)
{
   // Only update if move is valid
   if (!(x < 0 || x > 2 || y < 0 || y > 4) && (board[x][y] == 0))
   {
      board[x][y] = toupper(mark);
      n_moves++;
      return true;
   }
   else
      return false;
}

// Display the board and the pieces on it
void X_O_PyramidBoard::display_board()
{
   for (int i : {0, 1, 2})
   {
      if (i == 0)
      {
         cout << "\n                  |";
      }
      else if (i == 1)
      {
         cout << "\n         |";
      }
      else
      {
         cout << "\n|";
      }

      for (int j : {0, 1, 2, 3, 4})
      {
         if (board[i][j] != 1)
         {
            cout << " (" << i << "," << j << ")";
            cout << setw(2) << board[i][j] << " |";
         }
      }
      cout << "\n-----------------------------------------------";
   }
   cout << endl;
}

// Returns true if there is any winner
// either X or O
// Written in a complex way. DO NOT DO LIKE THIS.
bool X_O_PyramidBoard::is_winner()
{
   char row_win[3], col_win[3], diag_win[2];
   for (int i : {1, 2})
   {
      row_win[i] = board[i][1] & board[i][2] & board[i][3];
   }
   row_win[3] = board[2][0] & board[2][1] & board[2][2];
   row_win[4] = board[2][2] & board[2][3] & board[2][4];
   col_win[2] = board[0][2] & board[1][2] & board[2][2];
   diag_win[0] = board[2][0] & board[1][1] & board[0][2];
   diag_win[1] = board[2][4] & board[1][3] & board[0][2];

   for (int i : {1, 2})
   {
      if ((row_win[i] && (row_win[i] == board[i][1])) || (col_win[2] && (col_win[2] == board[2][2])))
      {
         return true;
      }
   }
   if ((row_win[3] && (row_win[3] == board[2][0])) || (row_win[4] && (row_win[4] == board[2][2])))
   {
      return true;
   }

   if ((diag_win[0] && diag_win[0] == board[1][1]) || (diag_win[1] && diag_win[1] == board[1][3]))
   {
      return true;
   }
   return false;
}

// Return true if 9 moves are done and no winner
bool X_O_PyramidBoard::is_draw()
{
   return (n_moves == 9 && !is_winner());
}

bool X_O_PyramidBoard::game_is_over()
{
   return n_moves >= 9;
}

// Connect 4 Board
// Set the board
Connect4_Board::Connect4_Board()
{
   n_rows = 6;
   n_cols = 7;
   board = new char *[n_rows];
   for (int i = 0; i < n_rows; i++)
   {
      board[i] = new char[n_cols];
      for (int j = 0; j < n_cols; j++)
         board[i][j] = 0;
   }
}

// Return true  if move is valid and put it on board
// within board boundaries in empty cell
// Return false otherwise
const int connect4Rows = 6;
const int connect4Cols = 7;

bool Connect4_Board::update_board(int col, int row, char mark) // we should ignnore the value of the row
{
   if (col < 0 || col >= connect4Cols)
   {
      return false; // Invalid column number
   }

   for (int i = connect4Rows - 1; i >= 0; --i)
   { // We start from the buttom
      if (board[i][col] == 0)
      { // Check for an empty cell in the column
         board[i][col] = toupper(mark);
         n_moves++;
         return true; // Successful move
      }
   }

   return false; // Column is full
}

// Display the board and the pieces on it
void Connect4_Board::display_board()
{
   for (size_t i = 0; i < 7; i++)
   {
      cout << setw(3) << i << ' ';
   }

   for (int i = 0; i < connect4Rows; ++i)
   {
      cout << "\n| ";
      for (int j = 0; j < connect4Cols; ++j)
      {
         cout << setw(2) << board[i][j] << " |";
      }
      cout << "\n-----------------------------------\n";
   }
   cout << endl;
}

// Returns true if there is any winner
// either X or O
// Written in a complex way. DO NOT DO LIKE THIS.

bool Connect4_Board::is_winner()
{
   // Check rows for a win
   for (int i = 0; i < connect4Rows; ++i)
   {
      for (int j = 0; j <= connect4Cols - 4; ++j)
      {
         if (board[i][j] != 0 &&
             board[i][j] == board[i][j + 1] &&
             board[i][j] == board[i][j + 2] &&
             board[i][j] == board[i][j + 3])
         {
            return true;
         }
      }
   }

   // Check columns for a win
   for (int i = 0; i <= connect4Rows - 4; ++i)
   {
      for (int j = 0; j < connect4Cols; ++j)
      {
         if (board[i][j] != 0 &&
             board[i][j] == board[i + 1][j] &&
             board[i][j] == board[i + 2][j] &&
             board[i][j] == board[i + 3][j])
         {
            return true;
         }
      }
   }

   // Check diagonals (positive slope) for a win
   for (int i = 0; i <= connect4Rows - 4; ++i) // i: 0-->2
   {
      for (int j = 0; j <= connect4Cols - 4; ++j) // j: 0-->3
      {
         if (board[i][j] != 0 &&
             board[i][j] == board[i + 1][j + 1] &&
             board[i][j] == board[i + 2][j + 2] &&
             board[i][j] == board[i + 3][j + 3])
         {
            return true;
         }
      }
   }

   // Check diagonals (negative slope) for a win
   for (int i = 3; i < connect4Rows; ++i)
   {
      for (int j = 0; j <= connect4Cols - 4; ++j)
      {
         if (board[i][j] != 0 &&
             board[i][j] == board[i - 1][j + 1] &&
             board[i][j] == board[i - 2][j + 2] &&
             board[i][j] == board[i - 3][j + 3])
         {
            return true;
         }
      }
   }
   return false;
}
// Return true if 42 moves are done and no winner
bool Connect4_Board::is_draw()
{
   return (n_moves == 42 && !is_winner());
}

bool Connect4_Board::game_is_over()
{
   return n_moves >= 42;
}

// 5x5 Board
// Set the board
X_O_5x5_Board::X_O_5x5_Board()
{
   n_rows = n_cols = 5;
   board = new char *[n_rows];
   for (int i = 0; i < n_rows; i++)
   {
      board[i] = new char[n_cols];
      for (int j = 0; j < n_cols; j++)
         board[i][j] = 0;
   }
}

// Return true  if move is valid and put it on board
// within board boundaries in empty cell
// Return false otherwise
bool X_O_5x5_Board::update_board(int x, int y, char mark)
{
   // Only update if move is valid
   if (!(x < 0 || x > 4 || y < 0 || y > 4) && (board[x][y] == 0))
   {
      board[x][y] = toupper(mark);
      n_moves++;
      return true;
   }
   else
      return false;
}

void X_O_5x5_Board::display_board()
{
   for (int i : {0, 1, 2, 3, 4})
   {

      cout << "\n| ";
      for (int j : {0, 1, 2, 3, 4})
      {
         cout << "(" << i << "," << j << ")";
         cout << setw(4) << board[i][j] << " |";
      }
      cout << "\n----------------------------------------------------------";
   }
   cout << endl;
}

int X_O_5x5_Board::game()
{
   int countx = 0;
   int county = 0;
   for (int i = 0; i < 5; ++i)
   {
      for (int j = 0; j < 5; ++j)
      {
         if (j <= 2)
         { // row
            if ((board[i][j] == board[i][j + 1]) && (board[i][j] == board[i][j + 2]))
            {
               if (board[i][j] == 'X')
               {
                  countx++;
               }
               else if (board[i][j] == 'O')
               {
                  county++;
               }
            }
         }

         if (i <= 2)
         { // column

            if ((board[i][j] == board[i + 1][j]) && (board[i][j] == board[i + 2][j]))
            {
               if (board[i][j] == 'X')
               {
                  countx++;
               }
               else if (board[i][j] == 'O')
               {
                  county++;
               }
            }
         }

         if (i <= 2 && j <= 2)
         { // diag

            if ((board[i][j] == board[i + 1][j + 1]) && (board[i][j] == board[i + 2][j + 2]))
            {
               if (board[i][j] == 'X')
               {
                  countx++;
               }
               else if (board[i][j] == 'O')
               {
                  county++;
               }
            }
         }

         if (i >= 2 && j >= 2)
         { // diag

            if ((board[i][j] == board[i - 1][j - 1]) && (board[i][j] == board[i - 2][j - 2]))
            {
               if (board[i][j] == 'X')
               {
                  countx++;
               }
               else if (board[i][j] == 'O')
               {
                  county++;
               }
            }
         }
      }
   }

   if (countx > county)
   {
      return 1;
   }
   if (countx < county)
   {
      return 2;
   }
   return 3;
}
bool X_O_5x5_Board::is_winner() { return true; }
bool X_O_5x5_Board::is_draw() { return true; }
bool X_O_5x5_Board::game_is_over()
{
   return n_moves >= 24;
}
