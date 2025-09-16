#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

const int MAXN = 200001;
int n;
int nalrari[MAXN];
vector<int> graph[MAXN];
int dp[MAXN][2];

int dfs(int root, int select){
    int& ret = dp[root][select];
    if(ret != -1) return ret;
    ret = (select == 1 ? nalrari[root] : 0);

    for(int child : graph[root]){
        if(select == 1) {
            ret += dfs(child, 0);
        } else {
            ret += max(dfs(child, 0), dfs(child, 1));
        }
    }
    return ret;
}

void trace(int root, int select, vector<int>& vec){
    if(select == 1) vec.push_back(root);
    for(int child : graph[root]){
        if(select == 1){
            trace(child, 0, vec);
        } else {
            if(dfs(child, 1) > dfs(child, 0)) trace(child, 1, vec);
            else trace(child, 0, vec);
        }
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++) cin >> nalrari[i];
    for(int i=2; i<=n; i++){
        int p; cin >> p;
        graph[p].push_back(i);
    }

    fill(&dp[0][0], &dp[0][0]+MAXN*2, -1);

    int att_val = dfs(1, 1);
    int unatt_val = dfs(1, 0);

    cout << att_val << ' ' << unatt_val << '\n';

    vector<int> attend, unattend;
    trace(1, 1, attend);
    trace(1, 0, unattend);

    sort(attend.begin(), attend.end());
    sort(unattend.begin(), unattend.end());
    for(int x : attend) cout << x << ' '; cout << -1 << '\n';
    for(int x : unattend) cout << x << ' '; cout << -1 << '\n';

    return 0;
}