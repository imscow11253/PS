#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

int n, m;
char board[10][10];
bool visited[10][10][10][10]; // red_x, red_y, blue_x, blue_y

int dx[4] = {-1,1,0,0}; // 상,하,좌,우
int dy[4] = {0,0,-1,1};

pair<int, int> move(int x, int y, int dx, int dy) {
    int cnt = 0;
    while (board[x+dx][y+dy] != '#' && board[x][y] != 'O') {
        x += dx;
        y += dy;
        cnt++;
        if (board[x][y] == 'O') break;
    }
    return {x, y};
}

int bfs(int rx, int ry, int bx, int by) {
    queue<tuple<int,int,int,int,int>> q;
    q.push({rx, ry, bx, by, 0});
    visited[rx][ry][bx][by] = true;

    while (!q.empty()) {
        auto [crx, cry, cbx, cby, cnt] = q.front(); q.pop();
        if (cnt >= 10) return -1;
        for (int dir=0; dir<4; dir++) {
            int nrx = crx, nry = cry, nbx = cbx, nby = cby;

            // Move red first
            int r_move = 0;
            while (board[nrx+dx[dir]][nry+dy[dir]] != '#' && board[nrx][nry] != 'O') {
                nrx += dx[dir]; nry += dy[dir]; r_move++;
                if (board[nrx][nry] == 'O') break;
            }
            int b_move = 0;
            while (board[nbx+dx[dir]][nby+dy[dir]] != '#' && board[nbx][nby] != 'O') {
                nbx += dx[dir]; nby += dy[dir]; b_move++;
                if (board[nbx][nby] == 'O') break;
            }
            // 파란 구슬이 빠진 경우 제외
            if (board[nbx][nby] == 'O') continue;
            // 빨간 구슬만 빠진 경우 성공
            if (board[nrx][nry] == 'O') return cnt+1;
            // 겹친 경우, 이동 많은 쪽 한칸 뒤로
            if (nrx == nbx && nry == nby) {
                if (r_move > b_move) {
                    nrx -= dx[dir]; nry -= dy[dir];
                } else {
                    nbx -= dx[dir]; nby -= dy[dir];
                }
            }
            if (!visited[nrx][nry][nbx][nby]) {
                visited[nrx][nry][nbx][nby] = true;
                q.push({nrx,nry,nbx,nby,cnt+1});
            }
        }
    }
    return -1;
}

int main() {
    cin >> n >> m;
    int rx, ry, bx, by;
    for (int i=0; i<n; i++) {
        string s; cin >> s;
        for (int j=0; j<m; j++) {
            board[i][j] = s[j];
            if (s[j] == 'R') { rx = i; ry = j; }
            if (s[j] == 'B') { bx = i; by = j; }
        }
    }
    cout << bfs(rx,ry,bx,by) << endl;
    return 0;
}