#include <iostream>
using namespace std;

int parent[100001];
int n, m;

int find(int node) {
    if (parent[node] == node) return node;
    return parent[node] = find(parent[node]);
}

void _union(int a, int b) {
    parent[find(a)] = find(b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i <= n; ++i) parent[i] = i;

    int cnt = 0;
    for (int i = 0; i < m; ++i) {
        int plane;
        cin >> plane;

        int gate = find(plane);
        if (gate == 0) break;

        _union(gate, gate - 1);
        cnt++;
    }

    cout << cnt << '\n';

    return 0;
}