#include <bits/stdc++.h>
using namespace std;

// TC = O(n!);
// SC = O(n*n)

// adding board values to our final answer
void addAnswer(vector<vector<int>> &board, vector<vector<vector<int>>> &ans, int n) {
	ans.push_back(board);
}

// function to find whether placing queen in next column is safe or not
bool isSafe(int row, int col, vector<vector<int>> &board, int n) {
	int x = row;
	int y = col;

	// checking in row
	while (y >= 0) {
		if (board[x][y] == 1) {
			return false;
		}
		y--;
	}

	// checking for upper diagonal
	x = row;
	y = col;
	while (x >= 0 && y >= 0) {
		if (board[x][y] == 1) {
			return false;
		}
		x--;
		y--;
	}

	// checking for lower diagonal
	x = row;
	y = col;
	while (x < n && y >= 0) {
		if (board[x][y] == 1) {
			return false;
		}
		x++;
		y--;
	}

	return true;
}

// function to find the possible solution to place n queens
void solve(int col, vector<vector<int>> &board, vector<vector<vector<int>>> &ans, int n) {
	// base case
	if (col == n) {
		addAnswer(board, ans, n);
		return;
	}

	for (int row=0; row<n; row++) {
		if (isSafe(row, col, board, n)) {
			board[row][col] = 1;
			solve(col+1, board, ans, n);
			board[row][col] = 0;
		}
	}
}

vector<vector<vector<int>>> nQueens(int n) {
	vector<vector<int>> board(n, vector<int> (n, 0));
	vector<vector<vector<int>>> ans;
	solve(0, board, ans, n);
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
