#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
#include <string>

using namespace std;

int n, m;
int mp[1001][1001] = {0,};
bool visit[1001][1001][2] = {0,};  // 3차원에서 2차원으로 줄이기
int min_value[1001][1001][2] = {INT_MAX,};  // 벽을 부순 경우와 그렇지 않은 경우로 나눔
queue<vector<int>> qu;
int result = INT_MAX;

void bfs() {
    while (!qu.empty()) {
        auto a = qu.front();
        qu.pop();

        int row = a[0];
        int col = a[1];
        int can_break = a[2];
        int cnt = a[3];

        if (row == n && col == m) {
            result = min(result, cnt);
            continue;
        }

        // 네 방향으로 이동
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (auto& dir : directions) {
            int newRow = row + dir.first;
            int newCol = col + dir.second;

            if (newRow > 0 && newRow <= n && newCol > 0 && newCol <= m) {
                // 벽이 있고, 부술 수 있을 때
                if (mp[newRow][newCol] == 1 && can_break && !visit[newRow][newCol][0]) {
                    qu.push({newRow, newCol, 0, cnt + 1});  // 벽을 부순 상태로 이동
                    visit[newRow][newCol][0] = true;
                }
                // 벽이 없을 때
                else if (mp[newRow][newCol] == 0 && !visit[newRow][newCol][can_break]) {
                    qu.push({newRow, newCol, can_break, cnt + 1});
                    visit[newRow][newCol][can_break] = true;
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    string line;
    for (int i = 1; i <= n; i++) {
        cin >> line;
        for (int j = 0; j < m; j++) {
            mp[i][j + 1] = line[j] - '0';
        }
    }

    qu.push({1, 1, 1, 1});  // 처음엔 벽을 부술 수 있는 상태로 시작
    visit[1][1][1] = true;
    bfs();

    if (result == INT_MAX) cout << -1;
    else cout << result;

    return 0;
}