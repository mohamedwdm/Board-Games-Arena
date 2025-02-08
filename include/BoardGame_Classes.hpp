#ifndef _BoardGame_CLASSES_H
#define _BoardGame_CLASSES_H
using namespace std;

class Board
{
protected:
    int n_rows, n_cols;
    char **board;
    int n_moves = 0;

public:
    // Return true  if move is valid and put it on board
    // within board boundaries in empty cell
    // Return false otherwise
    virtual bool update_board(int x, int y, char symbol) = 0;
    // Returns true if there is any winner
    // either X or O
    // Written in a complex way. DO NOT DO LIKE THIS.
    virtual bool is_winner() = 0;
    // Return true if all moves are done and no winner
    virtual bool is_draw() = 0;
    // Display the board and the pieces on it
    virtual void display_board() = 0;
    // Return true if game is over
    virtual bool game_is_over() = 0;
};

///////////////////////////////////////////
// This class represents a 3 x 3 board
// used in X_O game
class X_O_Board : public Board
{
public:
    X_O_Board();
    bool update_board(int x, int y, char mark);
    void display_board();
    bool is_winner();
    bool is_draw();
    bool game_is_over();
};

///////////////////////////////////////////
// This class represents a Pyramid board
class X_O_PyramidBoard : public Board
{
public:
    X_O_PyramidBoard();
    bool update_board(int x, int y, char mark);
    void display_board();
    bool is_winner();
    bool is_draw();
    bool game_is_over();
};

///////////////////////////////////////////
// This Class represents a connect four board
class Connect4_Board : public Board
{
public:
    Connect4_Board();
    bool update_board(int y, int x, char mark);
    void display_board();
    bool is_winner();
    bool is_draw();
    bool game_is_over();
};

///////////////////////////////////////////
// 5x5 X_O Board
class X_O_5x5_Board : public Board
{
public:
    X_O_5x5_Board();
    bool update_board(int x, int y, char mark);
    void display_board();
    bool is_winner();
    int game();
    bool is_draw();
    bool game_is_over();
};

///////////////////////////////////////////
// This class represents a player who has
// a name and a symbol to put on board
class Player
{
protected:
    string name;
    char symbol;

public:
    // Two constructors to initiate player
    // Give player a symbol to use in playing
    // It can be X or O or others
    // Optionally, you can give him ID or order
    // Like Player 1 and Player 2
    Player(char symbol); // Needed for computer players
    Player(int order, char symbol);
    // Get desired move: x y (each between 0 and 2)
    // Virtual (can change for other player types)
    virtual void get_move(int &x, int &y);
    // Give player info as a string
    string to_string();
    // Get symbol used by player
    char get_symbol();
};

///////////////////////////////////////////
// This class represents a connect 4 Player
class Connect4_player : public Player
{
public:
    using Player::Player;
    virtual void get_move(int &x, int &y);
};

///////////////////////////////////////////
// This class represents a random computer player
// that generates random positions x y (0 to 2)
// If invalid, game manager asks to regenerate
class RandomPlayer : public Player
{
protected:
    int dimension;

public:
    // Take a symbol and pass it to parent
    RandomPlayer(char symbol, int dimension);
    // Generate a random move
    void get_move(int &x, int &y);
};

///////////////////////////////////////////
// This class represents a random computer player in a pyramid board
class RandomPyramidPlayer : public RandomPlayer
{
protected:
    int dimension;

public:
    // Take a symbol and pass it to parent
    RandomPyramidPlayer(char symbol, int dimension);
    // Generate a random move
    void get_move(int &x, int &y);
};

////////////////////////////////////////////////////
// Connect4_RandomPlayer inheriting from connect4_player
class Connect4_RandomPlayer : public Connect4_player
{
protected:
    int dimension;

public:
    using Connect4_player::Connect4_player;
    // Take a symbol and pass it to parent
    Connect4_RandomPlayer(char symbol, int dimension);
    // Generate a random move
    virtual void get_move(int &x, int &y);
};

///////////////////////////////////////////
class GameManager
{
private:
    Board *boardPtr;
    Player *players[2];

public:
    GameManager(Board *, Player *playerPtr[2]);
    void run();
    // This method creates board and players
    // It displays board
    // While True
    //   For each player
    //      It takes a valid move as x, y pair
    //      It updates board and displays otit
    //      If winner, declare so and end
    //      If draw, declare so and end
};

///////////////////////////////////////////
// Connect 4 Game manager
// Gamemanager for Connect 4
class Connect4_GameManager
{
private:
    Connect4_Board *connect4_boardPtr;
    Connect4_player *connect4_players[2];

public:
    Connect4_GameManager(Connect4_Board *bPtr, Connect4_player *playerPtr[2]);
    void run();
};

// 5x5 Game Manager
///////////////////////////////////////////
class X_O_5x5_GameManager
{
private:
    X_O_5x5_Board *boardPtr;
    Player *players[2];

public:
    X_O_5x5_GameManager(X_O_5x5_Board *, Player *playerPtr[2]);
    void run();
};

///////////////////////////////////////////
// This is a game runner class
class GameRunner
{
private:
    void initializePlayers(Player *players[]);

public:
    void runX_O_Game();
    void runPyramidX_O_Game();
    void runConnect4_Game();
    void run5x5_XO_Game();
};

#endif
