#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
int n;
int arr[9];
vector<int> v;
bool visited[9];
int answer;
 
void dfs(int cnt) {
    if (v.size() == n) {
        int sum = 0;
        for (int i = 0; i < v.size(); i++) {
            if (i == v.size() - 1)
                continue;
            sum += abs(v[i] - v[i + 1]);
        }
        answer = max(answer, sum);
    }
 
    for (int i = 0; i < n; i++) {
        if (visited[i])
            continue;
        visited[i] = true;
        v.push_back(arr[i]);
 
        dfs(cnt + 1);
 
        visited[i] = false;
        v.pop_back();
    }
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    dfs(0);
    cout << answer;
}
