#include <iostream>
#include <vector>

using namespace std;

void fill(vector<vector<int>>& matrix, int x, int y, int targetColor, int newColor) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    if (x < 0 || x >= rows || y < 0 || y >= cols || matrix[x][y] != targetColor) {
        return;
    }

    matrix[x][y] = newColor;

    fill(matrix, x + 1, y, targetColor, newColor);
    fill(matrix, x - 1, y, targetColor, newColor);
    fill(matrix, x, y + 1, targetColor, newColor);
    fill(matrix, x, y - 1, targetColor, newColor);
}

void floodFill(vector<vector<int>>& matrix, int x, int y, int newColor) {
    int targetColor = matrix[x][y];
    if (targetColor != newColor) {
        fill(matrix, x, y, targetColor, newColor);
    }
}

int main() {
    int rows, cols;
    cin >> rows >> cols;
    vector<vector<int>> matrix(rows, vector<int>(cols));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> matrix[i][j];
        }
    }
    int startX, startY, newColor;
    cin >> startX >> startY >> newColor;
    floodFill(matrix, startX, startY, newColor);
    for (const auto& row : matrix) {
        for (int value : row) {
            cout << value << " ";
        }
        cout << endl;
    }

    return 0;
}
