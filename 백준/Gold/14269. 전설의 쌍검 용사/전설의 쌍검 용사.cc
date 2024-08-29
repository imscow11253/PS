#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    set<int> s;
    vector<vector<int>> L(n);

    // 입력 처리
    for (int i = 0; i < n; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        s.insert(a);
        L[i] = {a, b, c};
    }

    // 정렬
    vector<int> sorted_s(s.begin(), s.end());
    sort(sorted_s.begin(), sorted_s.end());

    // L을 끝 점 기준으로 정렬하고, 시작 점 기준으로 내림차순 정렬
    sort(L.begin(), L.end(), [](const vector<int>& a, const vector<int>& b) {
        return (a[2] < b[2]) || (a[2] == b[2] && a[1] > b[1]);
    });

    vector<int> S;
    int p = 0;
    int ans = 0;
    S.push_back(0);
    size_t x = 0;

    while (x < L.size()) {
        if (L[x][1] <= S.back() && S.back() <= L[x][2]) {
            if (S.back() == L[x][0]) {
                if (S.size() >= 2 && L[x][1] <= S[S.size() - 2] && S[S.size() - 2] <= L[x][2]) {
                    // Nothing to do
                } else {
                    S.push_back(L[x][2]);
                    ++ans;
                }
            }
            ++x;
        } else {
            while (p < sorted_s.size() && sorted_s[p] <= L[x][2]) {
                S.push_back(sorted_s[p]);
                ++p;
            }
            if (L[x][1] <= S.back() && S.back() <= L[x][2]) {
                // Nothing to do
            } else {
                S.push_back(L[x][2]);
                ++ans;
            }
        }
    }

    cout << sorted_s.size() + ans << '\n';

    return 0;
}