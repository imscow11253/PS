#include <iostream>

using namespace std;

int n;
int arr[100][100];
int result[100][100] = {0,};
int visit[100];

void dfs(int rootNode, int node){
    for(int i=0;i<n;i++){
        if(arr[node][i] == 1 && !visit[i]){
            result[rootNode][i] = 1;
            visit[i] = true;
            dfs(rootNode, i);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> arr[i][j];
        }
    }
    
    for(int i =0;i<n;i++){
        for(int j=0;j<n;j++) visit[j] = false;
        dfs(i,i);
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << result[i][j] << " ";
        }cout << '\n';
    }
    
    return 0;
}