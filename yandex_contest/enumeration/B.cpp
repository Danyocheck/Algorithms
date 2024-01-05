#include <iostream>
#include <vector>

using namespace std;

bool isSafe(vector<int>& board, int row, int col) {
    // Проверка, что нет ферзя в том же столбце или на одной диагонали
    for (int i = 0; i < row; ++i) {
        if (board[i] == col || abs(board[i] - col) == abs(i - row)) {
            return false;
        }
    }
    return true;
}

int countNQueensSolutions(int n, vector<int>& board, int row) {
    if (row == n) {
        // Достигнут конец доски - найдено допустимое решение
        return 1;
    }

    int count = 0;
    for (int col = 0; col < n; ++col) {
        if (isSafe(board, row, col)) {
            // Устанавливаем ферзя и переходим к следующей строке
            board[row] = col;
            count += countNQueensSolutions(n, board, row + 1);
        }
    }

    return count;
}

int main() {
    int n;
    cin >> n;

    vector<int> board(n, 0);

    int solutions = countNQueensSolutions(n, board, 0);

    cout << solutions << endl;

    return 0;
}