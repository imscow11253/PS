#include <iostream>

using namespace std;

long long dp(long long n) {
    long long res = 0, d = 1;
    while (n/d) {
        long long high = n/(d*10);
        long long cur = (n/d)%10;
        long long low = n%d;
        res += high * 45 * d;
        res += cur*(cur-1)/2*d;
        res += cur*(low+1);
        d *= 10;
    }
    return res;
}

int main() {
    long long a, b;
    cin >> a >> b;
    cout << dp(b) - dp(a-1) << endl;
}