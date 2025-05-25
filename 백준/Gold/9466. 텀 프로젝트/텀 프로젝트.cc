#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n;
int arr[100001];
int visited[100001]; // 0:미방문, 1:진행중, 2:완료
int ans;

void dfs(int now) {
    visited[now] = 1;
    int next = arr[now];
    if(visited[next] == 0){
        dfs(next);
    }
    else if(visited[next] == 1){
        // 싸이클 발견!
        for(int tmp = next; tmp != now; tmp = arr[tmp]){
            ans++;
        }
        ans++;
    }
    visited[now] = 2;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i=1; i<=n; i++) cin >> arr[i];
        memset(visited, 0, sizeof(visited));
        ans = 0;
        for(int i=1; i<=n; i++){
            if(visited[i] == 0) dfs(i);
        }
        cout << (n - ans) << "\n"; // 팀 없는 학생 수
    }
    return 0;
}