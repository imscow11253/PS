#include <iostream>
#include <queue>
#include <vector>
#include <set>

using namespace std;

int n,m,s;
vector<int> arr[100001];
bool visit[100001] = {};
set<int> fan;

queue<int> qu;
int check=0;

void bfs(){
    while(qu.size() != 0){
        int node = qu.front();
        // cout << node <<  '\n';
        qu.pop();
        
        if(fan.find(node) != fan.end()){
            continue;
        }
        if(arr[node].size()==0){
            check=1;
            return;
        }
        else{
            for(int a : arr[node]){
                qu.push(a);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    
    int a,b;
    while(m--){
        cin >> a >> b;
        if(visit[a]){
            arr[a].push_back(b);
        }
        else{
            vector<int> vec;
            vec.push_back(b);
            arr[a] = vec;
            visit[a]=1;
        }
    }
    
    cin >> s;
    int temp;
    while(s--){
        cin >> temp;
        fan.insert(temp);
    }
    
    // for(int i=0;i<=n;i++){
    //     for(int j : arr[i]){
    //         cout << j << " ";
    //     }cout << '\n';
    // }
    
    qu.push(1);
    bfs();
    
    if(!check) cout << "Yes";
    else cout << "yes";
    
    return 0;
}