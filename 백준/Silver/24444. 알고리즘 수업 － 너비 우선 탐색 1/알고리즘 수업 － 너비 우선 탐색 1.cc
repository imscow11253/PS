#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n,m,r;
vector<vector<int>> arr;
int order[100001] ={};
int visit[100001] ={};
int cnt=1;
queue<int> qu;

void travel(int r){
    // visit[r] = 1;
    // order[r] = cnt++;
    // for(auto a : arr[r]){
    //     if(!visit[a]){
    //         travel(a);
    //     }
    // }
    qu.pop();
    
    for(auto a : arr[r]){
        if(!visit[a]){
            visit[a] = 1;
            order[a] =cnt++;
            qu.push(a);   
        }
    }
    
    if(!qu.empty()){
        travel(qu.front());   
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m >> r;
    
    int a,b;
    int m2=m;
    while(m--){
        vector<int> vec;
        arr.push_back(vec);
    }
    vector<int> vec;
    arr.push_back(vec);
    
    while(m2--){
        cin >> a >> b;
        
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    
    for(int i =0;i<=n;i++){
        sort(arr[i].begin(), arr[i].end());
    }
    
    visit[r] =1;
    order[r] = cnt++;
    qu.push(r);
    travel(r);
    
    for(int i=1; i<=n;i++){
        cout << order[i] << '\n';
    }
    
    return 0;
}








