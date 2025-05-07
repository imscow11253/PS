#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

int n,m;
int arr[8];
set<vector<int>> appeared;

vector<int> temp;
bool visit[8]={0,};

void dfs(int index){
    temp.push_back(arr[index]);
    visit[index] = true;
    // cout <<"index : "<< index << '\n';
    if(temp.size() == m){
        if(appeared.find(temp) == appeared.end()){
            appeared.insert(temp);
            for(int i = 0; i <m; i++){
                cout << temp[i] << " ";
            }cout << '\n';
            return ;
        }
    }
    
    for(int i=0; i<n;i++){
        if(visit[i]) continue;
        dfs(i);
        temp.erase(temp.end()-1);
        visit[i] = false;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    for(int i =0;i<n;i++){
        cin >> arr[i];
    }
    
    sort(arr, arr+n);
    
    for(int i=0;i<n;i++){
        dfs(i);
        temp.erase(temp.end()-1);
        visit[i] = false;
    }
    
    return 0;
}