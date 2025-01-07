# Tic-Tac-Toe Game

This program implements a simple two-player Tic-Tac-Toe game in C++. Players take turns placing their markers (`X` or `O`) on a 3x3 grid. The game determines the winner or declares a draw when no valid moves are left. Players can also choose to play multiple rounds, and the program keeps track of the scores.

---

## Features

1. **Interactive Gameplay**: 
   - Players take turns entering the position to place their marker.
   - Input validation ensures players can only choose valid and unoccupied spots.

2. **Winner Determination**: 
   - The program checks rows, columns, and diagonals for a win condition after every move.

3. **Score Tracking**: 
   - Keeps track of how many games each player (`X` and `O`) has won.

4. **Play Again Option**: 
   - After a game ends, players can choose to play another round.

5. **Dynamic Game Board**: 
   - The game board updates dynamically after each move, displaying the current state of the game.

---

## How to Play

1. The game starts by displaying the initial board with numbers (1–9) representing positions.
2. Player `X` begins the game.
3. Players take turns entering the number corresponding to the position where they want to place their marker.
4. The program checks for the following conditions after each move:
   - **Win**: If a player aligns three of their markers in a row, column, or diagonal, they win.
   - **Draw**: If all spots are filled and no one wins, the game ends in a draw.
5. After the game ends, players can press `y` to start a new game or any other key to exit.

---

## Code Structure

- **Main Function**:
  - Initializes the game variables.
  - Calls the `Game` function for each round.
  - Prompts the player to play again after each round.
  - Displays the final score before exiting.

- **Helper Functions**:
  - `rows`, `cols`, `diag`: Check for winning conditions in rows, columns, and diagonals.
  - `drawBoard`: Displays the current game board.
  - `isValidSpots`: Validates the player's chosen position.
  - `Win`: Determines if a player has won and updates the game state.
  - `noWinner`: Checks for a draw.
  - `X_or_O`: Handles the logic for each player's turn.
  - `Game`: Manages the game loop for one round.
  - `PlayAgain`: Handles the logic for replaying the game.

---

