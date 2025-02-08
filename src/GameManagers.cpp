#include <bits/stdc++.h>
#include "../include/BoardGame_Classes.hpp"
using namespace std;

// Game manager for classic and pyramid X_O
GameManager::GameManager(Board *bPtr, Player *playerPtr[2])
{
    boardPtr = bPtr;
    players[0] = playerPtr[0];
    players[1] = playerPtr[1];
}

void GameManager::run()
{
    int x, y;

    boardPtr->display_board();

    while (!boardPtr->game_is_over())
    {
        for (int i : {0, 1})
        {
            players[i]->get_move(x, y);
            while (!boardPtr->update_board(x, y, players[i]->get_symbol()))
            {
                players[i]->get_move(x, y);
            }
            boardPtr->display_board();
            if (boardPtr->is_winner())
            {
                cout << players[i]->to_string() << " wins\n";
                return;
            }
            if (boardPtr->is_draw())
            {
                cout << "Draw!\n";
                return;
            }
        }
    }
}

// Game manager  for connect 4
Connect4_GameManager::Connect4_GameManager(Connect4_Board *bPtr, Connect4_player *playerPtr[2])
{
    connect4_boardPtr = bPtr;
    connect4_players[0] = playerPtr[0];
    connect4_players[1] = playerPtr[1];
}

void Connect4_GameManager::run()
{
    int x, y;
    connect4_boardPtr->display_board();

    while (!connect4_boardPtr->game_is_over())
    {
        for (int i = 0; i < 2; ++i)
        {
            connect4_players[i]->get_move(x, y);
            while (!connect4_boardPtr->update_board(x, y, connect4_players[i]->get_symbol()))
            {
                connect4_players[i]->get_move(y, x);
            }
            connect4_boardPtr->display_board();
            if (connect4_boardPtr->is_winner())
            {
                cout << connect4_players[i]->to_string() << " wins\n";
                return;
            }
            if (connect4_boardPtr->is_draw())
            {
                cout << "Draw!\n";
                return;
            }
        }
    }
};

// 5x5 Game Manager
X_O_5x5_GameManager::X_O_5x5_GameManager(X_O_5x5_Board *bPtr, Player *playerPtr[2])
{
    boardPtr = bPtr;
    players[0] = playerPtr[0];
    players[1] = playerPtr[1];
}

void X_O_5x5_GameManager::run()
{
    int x, y;

    boardPtr->display_board();

    while (!boardPtr->game_is_over())
    {
        for (int i : {0, 1})
        {
            players[i]->get_move(x, y);
            while (!boardPtr->update_board(x, y, players[i]->get_symbol()))
            {
                players[i]->get_move(x, y);
            }
            boardPtr->display_board();
        }
    }

    if ((boardPtr->game()) == 1)
    {
        cout << "player 1 wins\n";
        return;
    }
    if ((boardPtr->game()) == 2)
    {
        cout << "player 2 wins\n";
        return;
    }

    if ((boardPtr->game()) == 3)
    {
        cout << "draw\n";
        return;
    }
}