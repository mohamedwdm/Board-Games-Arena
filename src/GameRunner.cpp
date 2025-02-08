#include <bits/stdc++.h>
#include "../include/BoardGame_Classes.hpp"
using namespace std;

void GameRunner::initializePlayers(Player *players[])
{
    int playerChoice;
    players[0] = new Player(1, 'x');
    cout << "Press 1 if you want to play with computer: ";
    cin >> playerChoice;
    if (playerChoice != 1)
        players[1] = new Player(2, 'o');
    else
        // Player pointer points to child
        players[1] = new RandomPlayer('o', 3);
}

void GameRunner::runX_O_Game()
{
    Player *players[2];
    initializePlayers(players);
    GameManager boardGame(new X_O_Board(), players);
    boardGame.run();
}

void GameRunner::runPyramidX_O_Game()
{
    Player *players[2];
    initializePlayers(players);
    GameManager boardGame(new X_O_PyramidBoard(), players);
    boardGame.run();
}

void GameRunner::runConnect4_Game()
{
    int playerChoice;
    Connect4_player *players[2];
    players[0] = new Connect4_player(1, 'x');

    cout << "Press 1 if you want to play with computer: ";
    cin >> playerChoice;
    if (playerChoice != 1)
        players[1] = new Connect4_player(2, 'O');
    else
        // Player pointer points to child
        players[1] = new Connect4_RandomPlayer('O', 7);

    Connect4_GameManager connect_4_game(new Connect4_Board(), players);
    connect_4_game.run();
}

void GameRunner::run5x5_XO_Game()
{
    int choice;
    Player *players[2];
    players[0] = new Player(1, 'x');

    cout << "Press 1 if you want to play with computer: ";
    cin >> choice;
    if (choice != 1)
        players[1] = new Player(2, 'o');
    else
        // Player pointer points to child
        players[1] = new RandomPlayer('o', 5);

    X_O_5x5_GameManager x_o_game(new X_O_5x5_Board(), players);
    x_o_game.run();
}