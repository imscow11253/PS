#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int n, m;
int crane[50];
multiset<int> boxes;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> crane[i];
    }
    sort(crane, crane + n);

    cin >> m;
    for (int i = 0; i < m; i++) {
        int box;
        cin >> box;
        boxes.insert(box);
    }

    if (*boxes.rbegin() > crane[n - 1]) {
        cout << -1;
        return 0;
    }

    int result = 0;

    while (!boxes.empty()) {
        result++;
        for (int i = n - 1; i >= 0; i--) {
            auto it = boxes.upper_bound(crane[i]);
            if (it != boxes.begin()) {
                --it; 
                boxes.erase(it);
            }
        }
    }

    cout << result;
    return 0;
}