#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>

using namespace std;

int n, m;
int arr[1000][1000] = {0,};
int visit[1000][1000] = {0,};
int shape_id[1000][1000];  // 각 칸이 속한 모양의 번호
int shape_size[1000000];   // 각 모양의 크기 저장
int result = 0;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void dfs(int row, int col, int index, int &size) {
    visit[row][col] = 1;
    shape_id[row][col] = index;
    size++;

    for (int i = 0; i < 4; i++) {
        int newRow = row + dx[i];
        int newCol = col + dy[i];
        if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && !visit[newRow][newCol] && arr[newRow][newCol] == 1) {
            dfs(newRow, newCol, index, size);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    int index = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 1 && !visit[i][j]) {
                int size = 0;
                dfs(i, j, index, size);
                shape_size[index] = size;
                index++;
            }
        }
    }

    // 0을 1로 바꿨을 때 인접한 모양들의 크기를 합산
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 0) {
                set<int> neighboring_shapes;
                int total_size = 1;  // 현재 0을 1로 바꾼다

                // 상하좌우 인접한 모양의 크기를 합산
                for (int d = 0; d < 4; d++) {
                    int newRow = i + dx[d];
                    int newCol = j + dy[d];
                    if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && arr[newRow][newCol] == 1) {
                        neighboring_shapes.insert(shape_id[newRow][newCol]);
                    }
                }

                for (int shape : neighboring_shapes) {
                    total_size += shape_size[shape];
                }

                result = max(result, total_size);
            }
        }
    }

    cout << result << '\n';

    return 0;
}