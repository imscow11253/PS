#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, m;
    cin >> n >> k >> m;

    int turn = 0;

    while (true) {
        turn++;

        int kill = (k - 1) % n + 1;

        if (kill == m) {
            cout << turn;
            return 0;
        }

        if (m > kill)
            m = m - kill;
        else
            m = m + (n - kill);

        n--;
    }
}