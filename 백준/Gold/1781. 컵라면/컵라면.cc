#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int,int>> arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i].first >> arr[i].second;
    }
    sort(arr.begin(), arr.end());

    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=0; i<n; i++) {
        pq.push(arr[i].second);
        if(pq.size() > arr[i].first) { 
            pq.pop();
        }
    }
    long long ans = 0;
    while(!pq.empty()) {
        ans += pq.top();
        pq.pop();
    }
    cout << ans;
    return 0;
}