#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int paper[10][10];        // 10x10 크기의 종이
int paper_count[6] = {0};  // 각 크기별 색종이 사용 개수
int min_paper = 1e9;       // 최소 색종이 개수 (초기값은 매우 큰 값으로 설정)

bool can_attach(int x, int y, int size) {
    // 해당 위치에 size 크기의 색종이를 붙일 수 있는지 확인
    if (x + size > 10 || y + size > 10) {
        return false;  // 종이 경계를 벗어나는 경우
    }
    for (int i = x; i < x + size; ++i) {
        for (int j = y; j < y + size; ++j) {
            if (paper[i][j] != 1) {
                return false;  // 1이 아닌 칸이 포함된 경우
            }
        }
    }
    return true;
}

void attach(int x, int y, int size, int value) {
    // 색종이를 붙이거나 떼는 함수 (value: 0이면 색종이 붙임, 1이면 떼기)
    for (int i = x; i < x + size; ++i) {
        for (int j = y; j < y + size; ++j) {
            paper[i][j] = value;
        }
    }
}

void dfs(int count) {
    // 남아있는 모든 1을 덮었을 때
    bool completed = true;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (paper[i][j] == 1) {
                completed = false;
                break;
            }
        }
        if (!completed) break;
    }
    
    if (completed) {
        min_paper = min(min_paper, count);
        return;
    }

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (paper[i][j] == 1) {  // 1이 적힌 칸이 있으면
                for (int size = 5; size >= 1; --size) {  // 큰 색종이부터 시도
                    if (paper_count[size] < 5 && can_attach(i, j, size)) {
                        attach(i, j, size, 0);  // 색종이 붙이기
                        paper_count[size]++;
                        dfs(count + 1);
                        attach(i, j, size, 1);  // 원상 복구
                        paper_count[size]--;
                    }
                }
                return;  // 한 번의 시도 후에는 더 이상의 탐색이 필요 없음
            }
        }
    }
}

int main() {
    // 입력 받기
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            cin >> paper[i][j];
        }
    }

    // 백트래킹을 통한 최소 색종이 개수 탐색
    dfs(0);

    // 결과 출력
    if (min_paper == 1e9) {
        cout << -1 << endl;  // 덮을 수 없는 경우
    } else {
        cout << min_paper << endl;  // 최소 색종이 개수 출력
    }

    return 0;
}