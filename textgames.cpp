#include "textgames.hpp"
#include <algorithm>
#include <queue>
#include <fstream>

GameObject::GameObject(int sizeX, int sizeY)
{
    sizeGridX = sizeX;
    sizeGridY = sizeY;
    grid.resize(sizeGridY, std::vector<int>(sizeGridX, EMPTY_SPACE));

    PlayerX = 0;
    playerY = 0;
    goalX = sizeGridX - 1;
    goalY = sizeGridY - 1;

    grid[goalY][goalX] = TARGET;

    moveCount = 0;
    health = 3;
    score = 0;
}

void GameObject::display()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif

    std::cout << "Health: " << health << " | Moves: " << moveCount << " | Score: " << score << "\n";
    std::cout << "--------------------\n";

    for (int y = 0; y < sizeGridY; y++) {
        for (int x = 0; x < sizeGridX; x++) {
            if (x == PlayerX && y == playerY)
                std::cout << "P ";
            else if (grid[y][x] == TARGET)
                std::cout << "T ";
            else if (grid[y][x] == WALL)
                std::cout << "# ";
            else if (grid[y][x] == COLLECTIBLE)
                std::cout << "C ";
            else
                std::cout << ". ";
        }
        std::cout << "\n";
    }
    std::cout << "--------------------\n";
}

void GameObject::placeObstacles(int numObstacles, int numCollectibles)
{
    int wallsPlaced = 0;
    while (wallsPlaced < numObstacles)
    {
        int x = rand() % sizeGridX;
        int y = rand() % sizeGridY;

        if (grid[y][x] == EMPTY_SPACE && !(x == PlayerX && y == playerY) && !(x == goalX && y == goalY)) {
            grid[y][x] = WALL;

            if (isPathExist(PlayerX, playerY, goalX, goalY)) {
                wallsPlaced++;
            } else {
                grid[y][x] = EMPTY_SPACE;
            }
        }
    }

    int collectiblesPlaced = 0;
    while (collectiblesPlaced < numCollectibles)
    {
        int x = rand() % sizeGridX;
        int y = rand() % sizeGridY;

        if (grid[y][x] == EMPTY_SPACE && !(x == PlayerX && y == playerY) && !(x == goalX && y == goalY)) {
            grid[y][x] = COLLECTIBLE;
            collectiblesPlaced++;
        }
    }
}

void GameObject::movePlayer(char direction)
{
    int newX = PlayerX;
    int newY = playerY;

    if (direction == 'w') newY--;
    else if (direction == 's') newY++;
    else if (direction == 'a') newX--;
    else if (direction == 'd') newX++;
    else {
        std::cout << "Invalid move.\n";
        return;
    }

    if (newX < 0 || newX >= sizeGridX || newY < 0 || newY >= sizeGridY) {
        std::cout << "Out of bounds!\n";
        return;
    }

    if (grid[newY][newX] == COLLECTIBLE) {
        score++;
        grid[newY][newX] = EMPTY_SPACE;
        PlayerX = newX;
        playerY = newY;
        moveCount++;
        std::cout << "You collected a coin! Score: " << score << "\n";
        return;
    }

    if (grid[newY][newX] == WALL) {
        health--;
        std::cout << "Ouch! You hit a wall! Health: " << health << "\n";
        return;
    }

    PlayerX = newX;
    playerY = newY;
    moveCount++;
    std::cout << "Moved to (" << PlayerX << ", " << playerY << ")\n";
}

bool GameObject::isPathExist(int startX, int startY, int endX, int endY)
{
    if (grid[startY][startX] == WALL || grid[endY][endX] == WALL) return false;
    if (startX == endX && startY == endY) return true;

    std::queue<std::pair<int, int>> q;
    std::vector<std::vector<bool>> visited(sizeGridY, std::vector<bool>(sizeGridX, false));

    q.push({startY, startX});
    visited[startY][startX] = true;

    int dy[] = {-1, 1, 0, 0};
    int dx[] = {0, 0, -1, 1};

    while (!q.empty()) {
        auto [y, x] = q.front(); q.pop();

        for (int i = 0; i < 4; ++i) {
            int ny = y + dy[i], nx = x + dx[i];
            if (nx >= 0 && nx < sizeGridX && ny >= 0 && ny < sizeGridY &&
                !visited[ny][nx] && grid[ny][nx] != WALL) {
                if (nx == endX && ny == endY) return true;
                visited[ny][nx] = true;
                q.push({ny, nx});
            }
        }
    }
    return false;
}

bool GameObject::saveToFile(const std::string& filename)
{
    std::ofstream out(filename);
    if (!out) return false;

    out << sizeGridX << " " << sizeGridY << "\n";
    out << PlayerX << " " << playerY << " " << goalX << " " << goalY << "\n";
    out << moveCount << " " << health << " " << score << "\n";

    for (const auto& row : grid) {
        for (int cell : row) {
            out << cell << " ";
        }
        out << "\n";
    }

    return true;
}

bool GameObject::loadFromFile(const std::string& filename)
{
    std::ifstream in(filename);
    if (!in) return false;

    in >> sizeGridX >> sizeGridY;
    in >> PlayerX >> playerY >> goalX >> goalY;
    in >> moveCount >> health >> score;

    grid.resize(sizeGridY, std::vector<int>(sizeGridX));
    for (int y = 0; y < sizeGridY; ++y)
        for (int x = 0; x < sizeGridX; ++x)
            in >> grid[y][x];

    return true;
}
