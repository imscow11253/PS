#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int ans = -1;

    for (int five = n / 5; five >= 0; five--) {
        int rest = n - five * 5;
        if (rest % 2 == 0) {
            ans = five + rest / 2;
            break;
        }
    }

    cout << ans << '\n';
    return 0;
}