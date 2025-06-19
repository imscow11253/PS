#include <iostream>
using namespace std;
typedef long long ll;

ll count_ones_up_to(ll n) {
    if (n <= 0) return 0;
    ll res = 0;
    for (int k = 0; k < 61; ++k) { 
        ll cycle_len = 1LL << (k + 1);
        ll full_cycles = (n + 1) / cycle_len;
        res += full_cycles * (1LL << k);
        ll rest = (n + 1) % cycle_len;
        res += max(0LL, rest - (1LL << k));
    }
    return res;
}

int main() {
    ll A, B;
    cin >> A >> B;
    cout << count_ones_up_to(B) - count_ones_up_to(A - 1) << '\n';
    return 0;
}