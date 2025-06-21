#include <iostream>
#include <stack> // For undo functionality
using namespace std;

const int rows = 6, cols = 7;

// Function to check if the board is full
bool boardFull(char board[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (board[i][j] == '-') {
                return false;
            }
        }
    }
    return true;
}

// Function to check if the current player has won
bool winCheck(char board[rows][cols], char currentPlayer) {
    // Checking horizontally
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j <= cols - 4; j++) {
            if (board[i][j] == currentPlayer && board[i][j + 1] == currentPlayer &&
                board[i][j + 2] == currentPlayer && board[i][j + 3] == currentPlayer) {
                return true;
            }
        }
    }
    // Checking vertically
    for (int i = 0; i <= rows - 4; i++) {
        for (int j = 0; j < cols; j++) {
            if (board[i][j] == currentPlayer && board[i + 1][j] == currentPlayer &&
                board[i + 2][j] == currentPlayer && board[i + 3][j] == currentPlayer) {
                return true;
            }
        }
    }
    // Checking diagonally (left to right)
    for (int i = 0; i <= rows - 4; i++) {
        for (int j = 0; j <= cols - 4; j++) {
            if (board[i][j] == currentPlayer && board[i + 1][j + 1] == currentPlayer &&
                board[i + 2][j + 2] == currentPlayer && board[i + 3][j + 3] == currentPlayer) {
                return true;
            }
        }
    }
    // Checking diagonally (right to left)
    for (int i = 0; i <= rows - 4; i++) {
        for (int j = 3; j < cols; j++) {
            if (board[i][j] == currentPlayer && board[i + 1][j - 1] == currentPlayer &&
                board[i + 2][j - 2] == currentPlayer && board[i + 3][j - 3] == currentPlayer) {
                return true;
            }
        }
    }
    return false; // If no winning condition is met
}

// Function to drop a token
bool dropToken(char board[rows][cols], int column, char currentPlayer, stack<pair<int, int>> &history) {
    if (column < 0 || column >= cols) return false; // Invalid column
    for (int i = rows - 1; i >= 0; --i) {
        if (board[i][column] == '-') {
            board[i][column] = currentPlayer;  // Place token in the lowest empty row
            history.push({i, column});        // Record move for undo
            return true;
        }
    }
    return false;  // Column is full
}

// Function to display the board
void displayBoard(char board[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        cout << "\t";
        for (int j = 0; j < cols; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << "\t";
    for (int i = 1; i <= cols; i++) {
        cout << i << " ";
    }
    cout << endl;
}

// Reset the board for a new game
void resetBoard(char board[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            board[i][j] = '-';
        }
    }
}

int main() {
    char board[rows][cols];
    stack<pair<int, int>> moveHistory; // Stack to track moves for undo functionality
    int column;
    char currentPlayer = 'x';
    bool gameOver = false;
    int scoreX = 0, scoreO = 0; // Scores for both players
    string playerX, playerO;

    // Input player names
    cout << "=== Welcome to Connect Four ===" << endl;
    cout << "Enter Player 1 name (x): ";
    cin >> playerX;
    cout << "Enter Player 2 name (o): ";
    cin >> playerO;

    do {
        resetBoard(board);
        gameOver = false;
        displayBoard(board);

        while (!gameOver) {
            cout << "\n" << (currentPlayer == 'x' ? playerX : playerO) << "'s turn.";
            cout << " Enter column (1-7) to drop your token or 0 to undo: ";
            cin >> column;

            if (cin.fail() || column < 0 || column > 7) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid input! Please enter a valid column (1-7)." << endl;
                continue;
            }

            if (column == 0) { // Undo functionality
                if (moveHistory.empty()) {
                    cout << "No moves to undo!" << endl;
                    continue;
                } else {
                    auto lastMove = moveHistory.top();
                    moveHistory.pop();
                    board[lastMove.first][lastMove.second] = '-';
                    cout << "Last move undone." << endl;
                    displayBoard(board);
                    continue;
                }
            }

            if (!dropToken(board, column - 1, currentPlayer, moveHistory)) {
                cout << "Column " << column << " is full. Try another column!" << endl;
                continue;
            }

            displayBoard(board);

            if (winCheck(board, currentPlayer)) {
                cout << "Congratulations! " << (currentPlayer == 'x' ? playerX : playerO) << " wins!" << endl;
                if (currentPlayer == 'x') scoreX++;
                else scoreO++;
                gameOver = true;
            }

            if (boardFull(board)) {
                cout << "It's a tie! The board is full." << endl;
                gameOver = true;
            }

            // Switch player
            currentPlayer = (currentPlayer == 'x') ? 'o' : 'x';
        }

        // Display scores
        cout << "\nScores: " << playerX << " (x): " << scoreX << " | " << playerO << " (o): " << scoreO << endl;
        cout << "Play again? (y/n): ";
        char replay;
        cin >> replay;
        if (replay == 'n' || replay == 'N') break;

    } while (true);

    cout << "=== Thank you for playing Connect Four! ===" << endl;
    return 0;
}