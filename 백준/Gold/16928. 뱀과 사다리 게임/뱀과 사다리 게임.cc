#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

int n,m;
int arr[101] = {};
queue<pair<int,int>> qu;
bool visit[101] = {};
int result=INT_MAX;

void travel(){
    while(!qu.empty()){
        auto p = qu.front();
        qu.pop();
        int location = p.first;
        int cnt = p.second;
        
        for(int i=1;i<=6;i++){
            if(location+i > 100) break;
            if(!visit[location+i]){
                if(location+i == 100) result = min(result, cnt+1);
                else if(arr[location+i] != 0) { 
                    if(!visit[arr[location+i]]){
                        visit[arr[location+i]] = true; 
                        qu.push({arr[location+i], cnt+1});
                    }
                }
                else {visit[location+i] = true; qu.push({location+i, cnt+1});}
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    int a,b;
    for(int i =0;i<n+m;i++){
        cin >> a >> b;
        arr[a] = b;
    }
    
    qu.push({1,0});
    visit[1] = true;
    travel();
    
    cout << result;
    
    return 0;
}