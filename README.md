# Grid-Navigation-Game

## Project Overview
This is a text-based game created in C++ where the player navigates a randomly generated grid filled with obstacles to reach the target destination. 

## Objective
The player's goal is to move from the top-left corner (`P`) to the bottom-right corner (`T`), avoiding randomly placed obstacles (`#`). Movement is done using the keyboard (`W/A/S/D`). The player cannot move through walls and must find a valid path to the target

## Main Game Features
* **Procedural Maze Generation:** Each play session features a newly created grid with dynamically placed obstacles, offering fresh challenges.
* **Intuitive Player Control:** Navigating the map is straightforward with W/A/S/D inputs, complemented by robust checks for boundary and wall collisions.
* **Real-time Console Feedback:** The game actively updates the display to show the player's position and the maze layout, clearly indicating when the target is reached.

## Project Structure
* `main.cpp`: This is the **program's entry point**, containing the `main()` function. Its role is to initialize the game environment, create an instance of the `GameObject`, manage the central game loop, and handle user input to drive player actions.
* `textgames.hpp`: This **header file defines the public interface** for the `GameObject` class. It declares the class's structure, its private member variables, and its public methods. This separation allows `main.cpp` to interact with the game object without needing knowledge of its internal implementation details.
* `textgames.cpp`: This file contains the **complete implementation of all member functions for the `GameObject` class**. It encapsulates the core game logic, including methods for displaying the game grid, randomly placing obstacles, processing player movements, and handling various game conditions such as collisions and goal detection.

## Technologies Used
- **C++** – Core programming language.
- **STL Vectors** – Used to implement a 2D grid structure.
- **Random Number Logic** – For procedural obstacle generation.
- **Object-Oriented Design** – Encapsulation via a custom `GameObject` class.
- **CLI Interaction** – Simple console-based gameplay with real-time feedback.

## Example Gameplay
. . . . . . . . . .
P . # . . # . . . .
. . # . # . . . . .
. . # . . . # . . .
. . . . . . . # . .
. # . . . # . . . .
. . . # . . . . . .
. . # . # . . . . .
. . . . . . . . # .
. . . . . . . . . T

## How to Run
1.  **Clone the repository:**
    ```bash
    git clone https://github.com/rchowd9/Grid-Navigation-Game.git
    cd Grid-Navigation-Game
    ```
2.  **Compile the game:**
    ```bash
    g++ -o maze_game main.cpp textgames.cpp -std=c++11
    ```
3.  **Execute:**
    ```bash
    ./maze_game
    ```
    cd Grid-Navigation-Game
    ```
2.  **Compile the game:**
    ```bash
    g++ -o maze_game main.cpp textgames.cpp -std=c++11
    ```
3.  **Execute:**
    ```bash
    ./maze_game
    ```
