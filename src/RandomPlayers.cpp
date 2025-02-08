#include <bits/stdc++.h>
#include "../include/BoardGame_Classes.hpp"
using namespace std;

// Set player symbol and name as Random Computer Player
RandomPlayer::RandomPlayer(char symbol, int dimension) : Player(symbol)
{
    this->dimension = dimension;
    this->name = "Random Computer Player";
    cout << "My names is " << name << endl;
}

// Generate a random move
void RandomPlayer::get_move(int &x, int &y)
{
    x = (int)(rand() / (RAND_MAX + 1.0) * dimension);
    y = (int)(rand() / (RAND_MAX + 1.0) * dimension);
}

// Random Pyramid Player
// Set player symbol and name as Random Computer Player
RandomPyramidPlayer::RandomPyramidPlayer(char symbol, int dimension) : RandomPlayer(symbol, dimension){};

// Generate a random move
void RandomPyramidPlayer::get_move(int &x, int &y)
{
    static bool seeded = false;
    if (!seeded)
    {
        srand(time(NULL));
        seeded = true;
    }

    int max_cols = (dimension * 2) - 1;

    // Generate random y and calculate adjusted max_rows
    y = rand() % max_cols;
    int max_rows = dimension + abs(dimension - 1 - y);

    // Generate random x within adjusted range
    x = rand() % max_rows;
}

// Random connect 4 player
void Connect4_RandomPlayer::get_move(int &x, int &y)
{
    y = static_cast<int>(rand() / (RAND_MAX + 1.0) * dimension); // Generate random column
    x = static_cast<int>(rand() / (RAND_MAX + 1.0) * dimension); // Generate random column

    // Find the lowest available row in the selected column (if necessary in your game logic)
    // Optionally, you can implement additional logic here to handle checking for available rows.
    // If you're ignoring the rows completely for the random player, you may skip this step.
}

Connect4_RandomPlayer::Connect4_RandomPlayer(char symbol, int dimension) : Connect4_player(symbol)
{
    this->dimension = dimension;
    this->name = "Random Computer Player";
    cout << "My names is " << name << endl;
}