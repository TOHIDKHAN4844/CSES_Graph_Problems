#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll MOD = 1e9+7;
const vector<pair<pair<int,int>,char>> MOVES = {
    {{1,0},'D'},
    {{0,1},'R'},
    {{-1,0},'U'},
    {{0,-1},'L'}
};

void calculateMonsterTiming(queue<pair<pair<int,int>,int>>& monsterQueue, 
    vector<vector<int>>& monsterTime, vector<vector<char>>& maze, int rows) {
    int cols = monsterTime[0].size();
    vector<vector<int>> seen(rows, vector<int>(cols, 0));
    
    while(!monsterQueue.empty()) {
        auto curr = monsterQueue.front();
        monsterQueue.pop();
        int row = curr.first.first;
        int col = curr.first.second;
        int time = curr.second;
        
        seen[row][col] = 1;
        monsterTime[row][col] = time;
        
        for(auto move : MOVES) {
            int newRow = row + move.first.first;
            int newCol = col + move.first.second;
            if(newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && 
               !seen[newRow][newCol] && maze[newRow][newCol] != '#') {
                seen[newRow][newCol] = 1;
                monsterQueue.push({{newRow, newCol}, time + 1});
            }
        }
    }
}

bool findEscapePath(vector<vector<int>>& monsterTime, vector<vector<char>>& maze, 
    int startRow, int startCol, vector<vector<char>>& moveDir, vector<char>& path) {
    int rows = maze.size();
    int cols = maze[0].size();
    vector<vector<int>> seen(rows, vector<int>(cols, 0));
    
    queue<pair<pair<int,int>,int>> playerQueue;
    playerQueue.push({{startRow, startCol}, 0});
    seen[startRow][startCol] = 1;
    
    while(!playerQueue.empty()) {
        auto curr = playerQueue.front();
        playerQueue.pop();
        int row = curr.first.first;
        int col = curr.first.second;
        int time = curr.second;
        
        if((row == 0 || row == rows-1 || col == 0 || col == cols-1) && maze[row][col] == '.') {
            while(true) {
                path.push_back(moveDir[row][col]);
                if(moveDir[row][col] == 'R') col--;
                else if(moveDir[row][col] == 'L') col++;
                else if(moveDir[row][col] == 'U') row++;
                else if(moveDir[row][col] == 'D') row--;
                if(row == startRow && col == startCol) return true;
            }
        }
        
        for(auto move : MOVES) {
            int newRow = row + move.first.first;
            int newCol = col + move.first.second;
            char direction = move.second;
            
            if(newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && 
               maze[newRow][newCol] != '#' && !seen[newRow][newCol] && 
               maze[newRow][newCol] != 'M' && time + 1 < monsterTime[newRow][newCol]) {
                seen[newRow][newCol] = 1;
                playerQueue.push({{newRow, newCol}, time + 1});
                moveDir[newRow][newCol] = direction;
            }
        }
    }
    return false;
}

signed main() {
    int rows, cols;
    cin >> rows >> cols;
    
    if(rows == 1 && cols == 1) {
        cout << "YES\n0";
        return 0;
    }
    
    vector<vector<char>> maze(rows, vector<char>(cols, '#'));
    vector<vector<int>> monsterTime(rows, vector<int>(cols, INT_MAX));
    vector<vector<char>> moveDir(rows, vector<char>(cols, 'x'));
    vector<char> path;
    
    queue<pair<pair<int,int>,int>> monsterQueue;
    int playerRow, playerCol;
    
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            cin >> maze[i][j];
            if(maze[i][j] == 'M') monsterQueue.push({{i,j}, 0});
            if(maze[i][j] == 'A') {
                playerRow = i;
                playerCol = j;
            }
        }
    }
    
    if(playerRow == 0 || playerRow == rows-1 || playerCol == 0 || playerCol == cols-1) {
        cout << "YES\n0";
        return 0;
    }
    
    calculateMonsterTiming(monsterQueue, monsterTime, maze, rows);
    bool canEscape = findEscapePath(monsterTime, maze, playerRow, playerCol, moveDir, path);
    
    if(canEscape) {
        cout << "YES\n" << path.size() << endl;
        reverse(path.begin(), path.end());
        for(char move : path) cout << move;
    } else {
        cout << "NO";
    }
    return 0;
}
