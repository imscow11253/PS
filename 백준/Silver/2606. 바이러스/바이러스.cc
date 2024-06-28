#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m;
vector<int> arr[101];
int visit[101] ={};

void travel(int r){
    visit[r] =1;
    for(auto a : arr[r]){
        if(!visit[a]){
            travel(a);
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
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    
    travel(1);
    
    int cnt =0;
    for(int a : visit){
        if(a ==1){
            cnt++;
        }
    }
    cout << cnt-1;
    
    return 0;
}
