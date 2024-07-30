#include <iostream>
#include <vector>
#include <climits>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int n,m;
vector<pair<int,int>> vec;
vector<int> row;
vector<int> col;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    
    int a, b;
    while(m--){
        cin >> a >> b;
        row.push_back(a);
        col.push_back(b);
        vec.push_back({a,b});
    }
    
    sort(row.begin(), row.end());
    sort(col.begin(), col.end());
    
    int center_row = row[row.size()/2];
    int center_col = col[col.size()/2];
    
    int cnt =0;
    for(auto a :vec){
        cnt += abs(a.first - center_row);
        cnt += abs(a.second - center_col);
    }
    
    cout << cnt;
    
    return 0;
}