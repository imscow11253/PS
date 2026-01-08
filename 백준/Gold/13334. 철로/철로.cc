#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<int,int>> v;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        if (a > b) swap(a, b);
        v.push_back({b, a}); // (end, start)
    }

    int D;
    cin >> D;

    sort(v.begin(), v.end()); // end 기준 정렬

    priority_queue<int, vector<int>, greater<int>> pq;
    int ans = 0;

    for (auto &[end, start] : v) {
        pq.push(start);

        // 철로 범위 밖 제거
        while (!pq.empty() && pq.top() < end - D) {
            pq.pop();
        }

        ans = max(ans, (int)pq.size());
    }

    cout << ans << "\n";
    return 0;
}