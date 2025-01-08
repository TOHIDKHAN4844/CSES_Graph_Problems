#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MOD = 1e9+7;
vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void dfs(int x, int y, vector<vector<int>>& visited, vector<vector<char>>& grid, int rows, int cols) {
    visited[x][y] = 1;
    for (auto d : directions) {
        int nx = x + d.first;
        int ny = y + d.second;
        if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && !visited[nx][ny] && grid[nx][ny] != '#') {
            dfs(nx, ny, visited, grid, rows, cols);
        }
    }
}

signed main() {
    int rows, cols;
    cin >> rows >> cols;

    vector<vector<char>> grid(rows, vector<char>(cols));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> grid[i][j];
        }
    }

    vector<vector<int>> visited(rows, vector<int>(cols, 0));
    int regionCount = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (!visited[i][j] && grid[i][j] != '#') {
                regionCount++;
                dfs(i, j, visited, grid, rows, cols);
            }
        }
    }

    cout << regionCount << endl;
    return 0;
}
