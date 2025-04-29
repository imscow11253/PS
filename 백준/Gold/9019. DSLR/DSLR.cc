#include <iostream>
#include <tuple>
#include <queue>
#include <string>

using namespace std;

int sta, en;
bool visit[10000];

void initialize_visit(){
    for(int i =0;i<10000;i++) visit[i] = false;
}

string bfs(){
    initialize_visit();
    queue<pair<int,string>> qu;
    qu.push({sta,""});
    visit[sta] = true;
    
    while(!qu.empty()){
        auto a = qu.front();
        qu.pop();
        
        int num = a.first;
        string path = a.second;
        
        if(num == en){
            return path;
        }
        
        if(!visit[(num * 2)%10000]){
            visit[(num*2)%10000] = true;
            qu.push({(num*2)%10000, path+"D"});
        }
        if(num-1 >= 0 && !visit[num-1]){
            visit[num-1] = true;
            qu.push({num-1, path+"S"});
        }
        if(num == 0 && !visit[9999]){
            visit[9999] = true;
            qu.push({9999, path+"S"});
        }
        int digit = num / 1000;
        int left_move_num = (num * 10)%10000 + digit;
        if(!visit[left_move_num]){
            visit[left_move_num] = true;
            qu.push({left_move_num, path+"L"});
        }
        digit = num % 10;
        int rigth_move_num = (num / 10) + (digit* 1000);
        if(!visit[rigth_move_num]){
            visit[rigth_move_num] = true;
            qu.push({rigth_move_num, path+"R"});
        }
    }
    return "none";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;

    while(t--){
        cin >> sta >> en;
        cout << bfs() << '\n';
    }
    
    return 0;
}