#include <iostream>
#include <string>
#include <set>

using namespace std;

int n,m;
string arr[1000];
pair<int,int> parent[1000][1000];
int _rank[1000][1000];

pair<int,int> find(pair<int,int> a){
    if(a == parent[a.first][a.second]) return a;
    
    parent[a.first][a.second] = find(parent[a.first][a.second]);
    
    return parent[a.first][a.second];
}

void _union(pair<int,int> a, pair<int,int> b){
    // cout << a.first << " " << a.second << " " << b.first << " " << b.second << '\n';
    pair<int,int> a_parent = find(a);
    pair<int,int> b_parent = find(b);
    
    if(_rank[a_parent.first][a_parent.second] < _rank[b_parent.first][b_parent.second]){
        auto temp = a_parent;
        a_parent = b_parent;
        b_parent = temp;
    }
    
    parent[b_parent.first][b_parent.second] = a_parent;
    _rank[a_parent.first][a_parent.second] += _rank[b_parent.first][b_parent.second];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    for(int i =0;i<n;i++){
        cin >> arr[i];
    }
    
    for(int i =0;i<n;i++){
        for(int j=0;j<m;j++){
            parent[i][j] = {i,j};
            _rank[i][j] = 1;
        }
    }
    
    for(int i =0;i<n;i++){
        for(int j =0;j<m;j++){
            switch(arr[i][j]){
                case 'L':
                    if(j - 1 >=0) _union({i,j-1}, {i,j});
                    break;
                case 'R':
                    if(j + 1 < m) _union({i,j+1}, {i,j});
                    break;
                case 'U':
                    if(i - 1 >=0) _union({i-1, j}, {i,j});
                    break;
                case 'D':
                    if(i + 1 < n) _union({i+1, j}, {i,j});
                    break;
            }
        }
    }
    
    set<pair<int,int>> st;
    int cnt =0;
    for(int i =0;i<n;i++){
        for(int j =0;j<m;j++){
            auto a = find({i,j});
            if(st.find(a) == st.end()){
                st.insert(a);
                cnt++;
            }
        }
    }
    cout << cnt;
    
    return 0;
}