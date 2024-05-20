#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits>

using namespace std;

struct Position {
    int x, y, type;
    Position(int _x, int _y, int _type) : x(_x), y(_y), type(_type) {}
};


int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int boardSize;
    cin >> boardSize;
    vector<string> board(boardSize);
    const int INF = numeric_limits<int>::max();
    
    int startX = -1, startY = -1;
    int endX = -1, endY = -1;
    for (int i = 0; i < boardSize; ++i) {
        cin >> board[i];
        for (int j = 0; j < boardSize; ++j) {
            if (board[i][j] == 'S') {
                startX = i;
                startY = j;
            } else if (board[i][j] == 'F') {
                endX = i;
                endY = j;
            }
        }
    }

    const vector<int> dxG = {0, 0, 1, 1, 1, -1, -1, -1};
    const vector<int> dyG = {1, -1, 0, 1, -1, 0, 1, -1};
    const vector<int> dxK = {1, 1, 2, 2, -1, -1, -2, -2};
    const vector<int> dyK = {2, -2, 1, -1, 2, -2, 1, -1};
    
    vector<vector<vector<int>>> distanceMatrix(boardSize, vector<vector<int>>(boardSize, vector<int>(2, INF)));
    distanceMatrix[startX][startY][1] = 0;

    queue<Position> q;
    q.push(Position(startX, startY, 1));

    while (!q.empty()) {
        Position curr = q.front();
        q.pop();
        
        const vector<int>& dx = (curr.type == 0) ? dxG : dxK;
        const vector<int>& dy = (curr.type == 0) ? dyG : dyK;
        
        for (int i = 0; i < dx.size(); ++i) {
            int new_x = curr.x + dx[i];
            int new_y = curr.y + dy[i];
            
            if (!(new_x >= 0 && new_y >= 0 && new_x < boardSize && new_y < boardSize)) continue;
            
            int newType = 0;
            if (curr.type == 0) {
                if (board[new_x][new_y] == 'K') {
                    newType = 1;
                }
            } else {
                newType = 1;
                if (board[new_x][new_y] == 'G') {
                    newType = 0;
                }
            }
            if (distanceMatrix[new_x][new_y][newType] > distanceMatrix[curr.x][curr.y][curr.type] + 1) {
                distanceMatrix[new_x][new_y][newType] = distanceMatrix[curr.x][curr.y][curr.type] + 1;
                q.push(Position(new_x, new_y, newType));
            }
        }
    }

    int minDistance = min(distanceMatrix[endX][endY][0], distanceMatrix[endX][endY][1]);
    if (minDistance == INF) {
        cout << -1 << endl;
    } else {
        cout << minDistance << endl;
    }
}