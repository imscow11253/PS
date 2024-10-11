#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int v, e;
int node[20001] ={};
vector<int> edge[20001];

string check_bitate(){
    for(int i=1;i<=v;i++){
        if(node[i] ==0){
            queue<int> qu;
            qu.push(i);
            node[i] = 1;
            
            while(!qu.empty()){
                int node_temp = qu.front();
                qu.pop();
                
                for(int a : edge[node_temp]){
                    if(node[a] ==0){
                        qu.push(a);
                        if(node[node_temp]==1) node[a] = 2;
                        else node[a] =1;
                    }
                    else if(node[a] != node[node_temp]){
                        continue;
                    }
                    else{
                        return "NO";
                    }
                }
    
                // cout << "current : " << node_temp << '\n';
                // for(int i =1;i<=v;i++) cout << i << " : " << node[i]<< '\n';
            }
        }
    }
    return "YES";
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while(t--){
        for(int i=0;i<20001;i++) node[i] = 0;
        for(int i=0;i<20001;i++) edge[i].clear();
        cin >> v >> e;
        
        int a ,b;
        while(e--){
            cin >> a >> b;
            edge[a].push_back(b);
            edge[b].push_back(a);
        }
        
        cout << check_bitate() << '\n';
        // for(int i =1;i<=v;i++){
        //     cout << i << " : ";
        //     for(int b : edge[i])cout << b << " ";
        //     cout << '\n';
        // }
        // for(int i =1;i<=v;i++) cout << i << " : " << node[i]<< '\n';
    }
    
    return 0;
}