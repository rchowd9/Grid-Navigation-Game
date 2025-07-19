#ifndef TEXTGAMES_HPP
#define TEXTGAMES_HPP

#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <queue>
#include <fstream> // NEW

const int EMPTY_SPACE = 0;
const int WALL = 2;
const int PLAYER = 3;
const int TARGET = 4;
const int COLLECTIBLE = 5;

class GameObject
{
private:
    std::vector<std::vector<int>> grid;
    int sizeGridX, sizeGridY;
    int PlayerX, playerY;
    int goalX, goalY;

    int moveCount;
    int health;
    int score;

    bool isPathExist(int startX, int startY, int endX, int endY);

public:
    GameObject(int sizeX, int sizeY);
    void display();
    void placeObstacles(int numObstacles, int numCollectibles);
    void movePlayer(char direction);

    int getPlayerX() const { return PlayerX; }
    int getPlayerY() const { return playerY; }
    int getGoalX() const { return goalX; }
    int getGoalY() const { return goalY; }
    int getMoveCount() const { return moveCount; }
    int getHealth() const { return health; }
    int getScore() const { return score; }

    // NEW: Save/Load
    bool saveToFile(const std::string& filename);
    bool loadFromFile(const std::string& filename);
};

#endif
