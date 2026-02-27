#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    int result = 0;

    while(__builtin_popcount(n) > k){
        n++;
        result++;
    }

    cout << result;
    return 0;
}