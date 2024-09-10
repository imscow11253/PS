#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int M;
    cin >> M;

    unordered_map<int, int> count;
    long long total_sum = 0;
    long long total_xor = 0;

    count[0] = 1;
    total_sum = 0;
    total_xor = 0;

    for (int i = 0; i < M; ++i) {
        int query_type, x;
        cin >> query_type;

        if (query_type == 1) {
            cin >> x;
            count[x]++;
            total_sum += x;
            total_xor ^= x;
        } 
        else if (query_type == 2) {
            cin >> x;
            if (count[x] > 0) {
                count[x]--;
                total_sum -= x;
                total_xor ^= x;
            }
        } 
        else if (query_type == 3) {
            cout << total_sum << '\n';
        } 
        else if (query_type == 4) {
            cout << total_xor << '\n';
        }
    }

    return 0;
}