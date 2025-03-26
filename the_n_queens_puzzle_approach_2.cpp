#include <bits/stdc++.h>
using namespace std;

// Function to add the board configuration to the final answer
void addAnswer(vector<vector<int>> &board, vector<vector<vector<int>>> &ans, int n) {
    ans.push_back(board);
}

// Function to check if placing a queen at a given position is safe
bool isSafe(int row, int col, unordered_map<int, int> &rows, unordered_map<int, int> &left_diagonal, unordered_map<int, int> &right_diagonal) {
    return !(rows.count(row) || left_diagonal.count(row - col) || right_diagonal.count(row + col));
}

// Recursive function to find solutions for N-Queens problem
void solve(int col, vector<vector<int>> &board, unordered_map<int, int> &rows, unordered_map<int, int> &left_diagonal, unordered_map<int, int> &right_diagonal, vector<vector<vector<int>>> &ans, int n) {
    if (col == n) {
        addAnswer(board, ans, n);
        return;
    }
    for (int row = 0; row < n; row++) {
        if (isSafe(row, col, rows, left_diagonal, right_diagonal)) {
            board[row][col] = 1;
            rows[row] = 1;
            left_diagonal[row - col] = 1;
            right_diagonal[row + col] = 1;
            solve(col + 1, board, rows, left_diagonal, right_diagonal, ans, n);
            board[row][col] = 0;
            rows.erase(row);
            left_diagonal.erase(row - col);
            right_diagonal.erase(row + col);
        }
    }
}

// Function to find all solutions to the N-Queens problem
vector<vector<vector<int>>> nQueens(int n) {
    vector<vector<int>> board(n, vector<int>(n, 0));
    unordered_map<int, int> rows, left_diagonal, right_diagonal;
    vector<vector<vector<int>>> ans;
    solve(0, board, rows, left_diagonal, right_diagonal, ans, n);
    return ans;
}

// Function to print the board
void printBoards(const vector<vector<vector<int>>> &solutions) {
    for (const auto &board : solutions) {
        for (const auto &row : board) {
            for (int cell : row) {
                cout << (cell ? "Q " : ". ");
            }
            cout << endl;
        }
        cout << "\n";
    }
}

int main() {
    int n;
    cout << "Enter the value of N: ";
    cin >> n;
    vector<vector<vector<int>>> solutions = nQueens(n);
    cout << "Total solutions: " << solutions.size() << "\n\n";
    printBoards(solutions);
    return 0;
}
