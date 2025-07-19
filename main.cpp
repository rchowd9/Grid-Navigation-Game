#include "textgames.hpp"
#include <iostream>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <chrono> // For timing

int main()
{
    srand(static_cast<unsigned int>(time(0)));

    int sizeX = 10, sizeY = 10;
    int level = 1;
    int maxLevels = 5;
    bool loaded = false;

    GameObject game(sizeX, sizeY);

    std::cout << "1. New Game\n2. Load Game\nChoice: ";
    int choice;
    std::cin >> choice;

    if (choice == 2 && game.loadFromFile("savegame.txt")) {
        std::cout << "Game loaded successfully!\n";
        loaded = true;
    }

    while (level <= maxLevels)
    {
        if (!loaded) {
            int numObstacles = 10 + level * 2;
            int numCollectibles = 3 + level;
            game = GameObject(sizeX, sizeY);
            game.placeObstacles(numObstacles, numCollectibles);
        }
        loaded = false;

        bool gameOver = false;
        auto startTime = std::chrono::steady_clock::now();

        while (!gameOver)
        {
            game.display();
            std::cout << "Level " << level << " of " << maxLevels << "\n";
            std::cout << "Enter move (W/A/S/D), or 'Q' to save & quit: ";

            char move;
            std::cin >> move;
            move = std::tolower(move);

            if (move == 'q') {
                game.saveToFile("savegame.txt");
                std::cout << "Game saved. Exiting...\n";
                return 0;
            }

            game.movePlayer(move);

            if (game.getPlayerX() == game.getGoalX() && game.getPlayerY() == game.getGoalY())
            {
                gameOver = true;
                auto endTime = std::chrono::steady_clock::now();
                int duration = std::chrono::duration_cast<std::chrono::seconds>(endTime - startTime).count();

                std::cout << "\n******** Level Complete! ********\n";
                std::cout << "Time: " << duration << " sec | Moves: " << game.getMoveCount() << "\n";

                int timeBonus = std::max(0, 100 - duration);
                int movePenalty = game.getMoveCount();
                int totalScore = game.getScore() + timeBonus - movePenalty;

                std::cout << "Score: " << game.getScore() << " + " << timeBonus << " - " << movePenalty
                          << " = " << totalScore << "\n";
                std::cout << "*********************************\n";

                level++;
            }
            else if (game.getHealth() <= 0)
            {
                gameOver = true;
                std::cout << "\n******** GAME OVER ********\n";
                std::cout << "You ran out of health on level " << level << ".\n";
                std::cout << "Moves: " << game.getMoveCount() << " | Score: " << game.getScore() << "\n";
                return 0;
            }
        }
    }

    std::cout << "\n🎉 YOU COMPLETED ALL LEVELS! WELL DONE!\n";
    return 0;
}
