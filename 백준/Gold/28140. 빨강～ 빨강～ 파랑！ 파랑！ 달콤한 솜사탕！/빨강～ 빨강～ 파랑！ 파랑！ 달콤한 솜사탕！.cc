#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int n, q;
vector<int> r;
vector<int> b_vec;
string str;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> q;
    cin >> str;
    
    for(int i = 0; i < n; i++){
        if(str[i] == 'R') r.push_back(i);
        if(str[i] == 'B') b_vec.push_back(i);
    }
    
    int start, end;
    while(q--){
        cin >> start >> end;
        
        // Find the first 'R' within the range [start, end]
        auto r_sta = lower_bound(r.begin(), r.end(), start);
        if(r_sta == r.end() || r_sta + 1 == r.end() || *(r_sta + 1) > end) {
            cout << -1 << '\n';
            continue;
        }
        
        // Ensure both 'R's are within the range [start, end]
        int a = *r_sta;
        int b = *(r_sta + 1);
        if(a > end || b > end) {
            cout << -1 << '\n';
            continue;
        }
        
        // Find the first 'B' within the range [b + 1, end]
        auto b_sta = lower_bound(b_vec.begin(), b_vec.end(), b + 1);
        if(b_sta == b_vec.end() || b_sta + 1 == b_vec.end() || *(b_sta + 1) > end) {
            cout << -1 << '\n';
            continue;
        }
        
        // Ensure both 'B's are within the range [start, end]
        int c = *b_sta;
        int d = *(b_sta + 1);
        if(c > end || d > end) {
            cout << -1 << '\n';
        } else {
            if(a < b && b < c && c < d){
                cout << a << " " << b << " " << c << " " << d << '\n';
            } else {
                cout << -1 << '\n';
            }
        }
    }
    
    return 0;
}