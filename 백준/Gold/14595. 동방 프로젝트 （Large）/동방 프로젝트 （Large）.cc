#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,m;
vector<pair<int,int>> panel;
vector<pair<int,int>> result;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    int sta, end;
    
    if(m ==0 ) {cout << n; exit(0);}
    
    for(int i=0;i<m;i++){
        cin >> sta >> end;
        panel.push_back({sta, end});
    }
    
    sort(panel.begin(), panel.end());
    
    pair<int,int> index = panel[0];
    for(int i =1;i<m;i++){
        int l = panel[i].first;
        int r = panel[i].second;
        
        if(l <= index.second){
            if(r < index.second) continue;
            else{
                index.second = r;
            }
        }
        else{
            result.push_back(index);
            index = panel[i];
        }
    }
    result.push_back(index);
    
    // for(auto a : result){
    //     cout << a.first << " " << a.second << '\n';
    // }
    
    int pointer=0;
    int room=0;
    for(int i =1;i<=n;i++){
        if(result[pointer].first == i){
            i = result[pointer].second;
            pointer++;
            room++;
        }
        else{
            room++;
        }
    }
    
    cout << room;
    
    return 0;
}