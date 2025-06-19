#include <iostream>
#include <vector>
#include <string>
using namespace std;

int N;
vector<string> arr;

void draw(int n, int x, int y) {
    // n: 현재 삼각형의 높이, (x, y): 꼭대기 좌표
    if (n == 3) {
        arr[x][y] = '*';
        arr[x+1][y-1] = '*';
        arr[x+1][y+1] = '*';
        for (int i = -2; i <= 2; ++i)
            arr[x+2][y+i] = '*';
        return;
    }
    int half = n/2;
    draw(half, x, y);                 // 위 삼각형
    draw(half, x+half, y-half);       // 아래 왼쪽
    draw(half, x+half, y+half);       // 아래 오른쪽
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    arr = vector<string>(N, string(2*N-1, ' ')); // 전체는 2*N-1칸

    draw(N, 0, N-1); // 꼭대기는 (0, N-1)
    for (int i = 0; i < N; ++i) {
        cout << arr[i] << '\n';
    }
    return 0;
}