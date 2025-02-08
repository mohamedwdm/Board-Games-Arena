#include "../include/BoardGamesIncludes.cpp"
using namespace std;

int main()
{
    GameRunner boardGames;
    int playerChoice, gameChoice;
    string games[4] = {"X_O Classic Game", "Pyramid X_O Game", "Connect 4", "5x5 X_O Game"};
    cout << "Welcome to Board Games \n";
    cout << "Please Choose your Game : \n";
    for (int i = 0; i < sizeof(games) / sizeof(games[0]); i++)
    {
        cout << i + 1 << "- " << games[i] << '\n';
    }
    cin >> gameChoice;
    switch (gameChoice)
    {
    case 1:
        boardGames.runX_O_Game();
        break;
    case 2:
        boardGames.runPyramidX_O_Game();
        break;
    case 3:
        boardGames.runConnect4_Game();
        break;
    case 4:
        boardGames.run5x5_XO_Game();
        break;
    default:
        cout << "Game is not supported or undefined.\n";
        break;
    }

    system("pause");
}