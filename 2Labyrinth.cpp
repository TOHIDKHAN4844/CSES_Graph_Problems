#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ppi pair<pair<int, char>, pair<int, int>>

vector<pair<pair<int, int>, char>> directions = {
    {{1, 0}, 'D'}, {{0, 1}, 'R'}, {{-1, 0}, 'U'}, {{0, -1}, 'L'}
};

bool found = false;

void bfs(vector<vector<int>>& visited, vector<vector<char>>& grid, vector<vector<char>>& direction,
         queue<pair<int, int>>& q, int& steps, int rows, int cols, vector<char>& path) {
    int startX = q.front().first;
    int startY = q.front().second;

    while (!q.empty()) {
        auto current = q.front();
        q.pop();
        int x = current.first, y = current.second;

        if (grid[x][y] == 'B') {
            while (true) {
                path.push_back(direction[x][y]);
                if (path.back() == 'U') x++;
                else if (path.back() == 'D') x--;
                else if (path.back() == 'L') y++;
                else if (path.back() == 'R') y--;

                if (x == startX && y == startY) {
                    steps = path.size();
                    found = true;
                    return;
                }
            }
        }

        for (auto dir : directions) {
            int nx = x + dir.first.first;
            int ny = y + dir.first.second;
            char move = dir.second;

            if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && !visited[nx][ny] && grid[nx][ny] != '#') {
                direction[nx][ny] = move;
                visited[nx][ny] = 1;
                q.push({nx, ny});
            }
        }
    }
}

signed main() {
    int rows, cols;
    cin >> rows >> cols;

    vector<vector<char>> grid(rows, vector<char>(cols));
    vector<vector<int>> visited(rows, vector<int>(cols, 0));
    vector<vector<char>> direction(rows, vector<char>(cols, 0));
    queue<pair<int, int>> q;
    int steps = 0;
    vector<char> path;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == '#') visited[i][j] = 1;
            if (grid[i][j] == 'A') {
                q.push({i, j});
                visited[i][j] = 1;
            }
        }
    }

    bfs(visited, grid, direction, q, steps, rows, cols, path);

    if (found) {
        cout << "YES" << endl;
        cout << steps << endl;
        reverse(path.begin(), path.end());
        for (char move : path) cout << move;
    } else {
        cout << "NO";
    }
    cout << endl;

    return 0;
}
