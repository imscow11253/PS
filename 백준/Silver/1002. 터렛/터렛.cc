#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int x1, y1, r1, x2, y2, r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

        int dx = x1 - x2;
        int dy = y1 - y2;
        int d2 = dx*dx + dy*dy;

        if(x1 == x2 && y1 == y2 && r1 == r2){
            cout << -1 << '\n';
            continue;
        }

        int sum = r1 + r2;
        int diff = abs(r1 - r2);

        if(d2 > sum * sum) cout << 0 << '\n';
        else if(d2 == sum * sum) cout << 1 << '\n';
        else if(d2 < diff * diff) cout << 0 << '\n';
        else if(d2 == diff * diff) cout << 1 << '\n';
        else cout << 2 << '\n';
    }
}