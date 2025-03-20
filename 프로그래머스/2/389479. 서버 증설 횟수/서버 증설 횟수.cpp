#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    
    queue<pair<int,int>> increaseInfo; // {종료 시점, 증설된 개수}
    int cur_server_num=0;
    for(int i =0;i<24;i++){
        cout << "i : " << i << ", server : " << cur_server_num << '\n';
        int player = players[i];
        
        if(player/m > cur_server_num){
            cout << "created : " << i << '\n';
            increaseInfo.push({i+k-1, player/m - cur_server_num});
            answer += player/m - cur_server_num;
            cur_server_num += player/m - cur_server_num;
        }
        
        if(increaseInfo.empty()) continue;
        if(increaseInfo.front().first == i){
            cout << "removed : " << i << '\n';
            auto temp = increaseInfo.front();
            increaseInfo.pop();
            cur_server_num -= temp.second;
        }
    }
    
    return answer;
}