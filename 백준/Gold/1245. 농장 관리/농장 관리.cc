#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
vector<vector<int>> grid;
vector<vector<bool>> visited;

int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};

bool isValid(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < M;
}

bool dfs(int x, int y, int height) {
    bool isPeak = true;
    visited[x][y] = true;

    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (isValid(nx, ny)) {
            if (grid[nx][ny] > height) {
                isPeak = false;
            }
            if (!visited[nx][ny] && grid[nx][ny] == height) {
                if (!dfs(nx, ny, height)) {
                    isPeak = false;
                }
            }
        }
    }
    return isPeak;
}

int main() {
    cin >> N >> M;
    grid.resize(N, vector<int>(M));
    visited.resize(N, vector<bool>(M, false));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> grid[i][j];
        }
    }

    int peakCount = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!visited[i][j]) {
                if (dfs(i, j, grid[i][j])) {
                    peakCount++;
                }
            }
        }
    }

    cout << peakCount << endl;
    return 0;
}