#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int dp[121][41] = {0,};

int solution(vector<vector<int>> info, int n, int m) {
    int answer = 0;
    
    //dp initialize
    for(int j=0;j<info.size();j++){
        for(int i =0;i<m;i++){
            if(i ==0 && j==0){
                dp[i][j] = info[0][0];
            }
            else if(i==0){
                dp[i][j] = dp[i][j-1] + info[j][0];
            }
            else if(j==0){
                if(info[0][1] > i){
                    dp[i][j] = info[0][0];
                }
                else dp[i][j] = 0;
            }
            else {
                if(i-info[j][1] >= 0) {
                    dp[i][j] = min(dp[i][j-1] + info[j][0], dp[i-info[j][1]][j-1]);
                }
                else dp[i][j] = dp[i][j-1]  +info[j][0] ;
            }
        }
    }
    for(int i =0;i<m;i++){
        for(int j=0;j<info.size();j++){
            cout << dp[i][j] << " " ;
        } cout << '\n';
    }
    
    answer = dp[m-1][info.size()-1];
    if(answer >= n) return -1;
    
    return answer;
}