// textgames.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
#include <vector>
#include <cstdlib>

const int EMPTY_SPACE = 0;
const int WALL = 2;
const int PLAYER = 3;
const int TARGET = 4;

class GameObject
{
private:
    vector<vector<int>> grid;
    int sizeGridX, sizeGridY;
    int PlayerX, playerY;
    int goalX, goalY;

public:
    GameObject(int sizeX, int sizeY);
    void display();
    void placeObstacles(int count);
    void movePlayer(char direction);
};




// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
