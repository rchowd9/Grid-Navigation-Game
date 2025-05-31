#include "textgames.cpp"

GameObject::GameObject(int sizeX, int sizeY)
{
    sizeGridX = sizeX;
    sizeGridY = sizeY;
    grid.resize(sizeGridY, vector<int>(sizeGridX, EMPTY_SPACE));

    PlayerX = 0;
    playerY = 0;
    goalX = sizeGridX - 1;
    goalY = sizeGridY - 1;

    grid[goalY][goalX] = TARGET;
}

void GameObject::display()
{
    for (int y = 0; y < sizeGridY; y++)
    {
        for (int x = 0; x < sizeGridX; x++)
        {
            if (x == PlayerX && y == playerY)
                cout << "P ";
            else if (grid[y][x] == TARGET)
                cout << "T ";
            else if (grid[y][x] == WALL)
                cout << "# ";
            else
                cout << ". ";
        }
        cout << endl;
    }
}

void GameObject::placeObstacles(int numObstacles)
{
    srand(time(0));
    int placement = 0;
    while (placement < numObstacles)
    {
        int x = rand() % sizeGridX;
        int y = rand() % sizeGridY;
        if (grid[y][x] == EMPTY_SPACE && !(x == PlayerX && y == playerY) && !(x == goalX && y == goalY))
        {
            grid[y][x] = WALL;
            placement++;
        }
	}
}

void GameObject::movePlayer(char direction)
{
    int newX = PlayerX;
    int newY = playerY;

    if (direction == 'w')
    {
        newY--;
    }

    else if (direction == 's')
    {
        newY++;
    }

    else if (direction == 'a')
    {
        newX--;
    }

    else if (direction == 'd')
    {
        newX++;
	}

    else
    {
        cout << "Invalid move. Use 'w', 'a', 's', 'd' to move." << endl;
        return;
    }

    if (newX < 0 || newX >= sizeGridX || newY < 0 || newY >= sizeGridY)
    {
        cout << "Move out of bounds!" << endl;
        return;
	}

    if( grid[newY][newX] == WALL)
    {
        cout << "You hit a wall!" << endl;
        return;
	}

    PlayerX = newX;
    playerY = newY;

    if (PlayerX == goalX && playerY == goalY)
    {
        cout << "Congratulations! You've reached the target!" << endl;
    }

    else
    {
        cout << "You moved to (" << PlayerX << ", " << playerY << ")." << endl;
	}
}
