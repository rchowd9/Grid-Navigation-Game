#include "textgames.hpp"

int main()
{
    int sizeX = 10, sizeY = 10;
    GameObject game(sizeX, sizeY);

    game.placeObstacles(15);

    while (true)
    {
        game.display();
        char move;
        cout << "Enter move (W/A/S/D): ";
        cin >> move;
        game.movePlayer(tolower(move));
    }

    return 0;
}