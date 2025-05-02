#include <iostream>
#include <queue>

using namespace std;

int n,k;
bool visit[100001]={0,};

int bfs(){
    queue<pair<int,int>> qu;
    qu.push({n,0});
    visit[n] = true;
    
    while(!qu.empty()){
        auto a = qu.front();
        qu.pop();
        
        int location = a.first;
        int time_clock = a.second;
        
        if(location == k) return time_clock;
        
        if(location * 2 < 100001 && !visit[location*2]){
            visit[location*2] = true;
            qu.push({location *2, time_clock});
        }
        if(location -1 >=0 && !visit[location -1]){
            visit[location-1] = true;
            qu.push({location-1, time_clock+1});
        }
        if(location +1 < 100001 && !visit[location +1]){
            visit[location+1] = true;
            qu.push({location+1, time_clock+1});
        }
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> k;
    cout << bfs();
    
    return 0;
}