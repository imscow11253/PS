#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int MAX_K = 20;
    double val[MAX_K];
    
    int K;
    cin >> K;
    while (K--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> val[i];
        }
        sort(val, val + n);
        double sum = 0.0;
        double max = 0.0;
        bool good = false;
        for (int i = 0; i < n; i++) {
            max = val[i] > max ? val[i] : max;
            sum += val[i];
            if (sum - max >= max) {
                good = true;
                break;
            }
        }
        if (good) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
}

