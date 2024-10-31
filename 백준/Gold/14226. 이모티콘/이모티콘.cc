#include <iostream>
#include <queue>
#include <vector>
#include <tuple>

using namespace std;

int min_time_to_make_emoticons(int S) {
    queue<tuple<int, int, int>> q;
    vector<vector<bool>> visited(S + 1, vector<bool>(S + 1, false));
    
    q.push({1, 0, 0});
    visited[1][0] = true;

    while (!q.empty()) {
        //올 이런 문법도 가능하네 wooooooow 외쳐 갓 C++
        auto [screen, clipboard, time_] = q.front();
        q.pop();
        
        if (screen == S) return time_;

        // visit의 row 는 screen, col은 clipboard를 나타낸다. 즉 해당 정보를 qu에 넣었던 적이 있는지 없는지를 check하는 것 
        // 2차원 배열이라고 생각하지 말고 각 정보를 가지는 visit 이라고 생각하면 편할 것 같다. 

        // 연산 3개에 대해서 각각 경우의 수를 큐에 넣어주는 것이다. 
        // 1. 화면의 이모티콘을 클립보드에 복사
        if (!visited[screen][screen]) {
            visited[screen][screen] = true;
            q.push({screen, screen, time_ + 1});
        }

        // 2. 클립보드의 이모티콘을 화면에 붙여넣기
        if (clipboard > 0 && screen + clipboard <= S && !visited[screen + clipboard][clipboard]) {
            visited[screen + clipboard][clipboard] = true;
            q.push({screen + clipboard, clipboard, time_ + 1});
        }

        // 3. 화면의 이모티콘 중 하나 삭제
        if (screen > 1 && !visited[screen - 1][clipboard]) {
            visited[screen - 1][clipboard] = true;
            q.push({screen - 1, clipboard, time_ + 1});
        }
    }
    return -1;
}

int main() {
    int n;
    cin >> n;
    cout << min_time_to_make_emoticons(n);
    return 0;
}