#include <iostream>
#include <queue>

using namespace std;

long long a,b;

int bfs(){
    queue<pair<long long, int>> qu;
    qu.push({a,1});
    
    while(!qu.empty()){
        long long candi = qu.front().first;
        int cnt = qu.front().second;
        qu.pop();
        
        if(candi > b) continue;
        if(candi == b) return cnt;
        
        qu.push({candi *2,cnt+1});
        qu.push({candi*10 +1,cnt+1});
    }
    
    return -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> a >> b;
    cout << bfs();
    
    return 0;
}