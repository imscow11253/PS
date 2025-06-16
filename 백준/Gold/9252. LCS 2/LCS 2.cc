#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

string str1, str2;
int dp[1001][1001] = {0,};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> str1 >> str2;
    for (int i=1; i<=str1.length(); i++) {
        for (int j=1; j<=str2.length(); j++) {
            if (str1[i-1] == str2[j-1]) {
                if (i==0 || j==0) dp[i][j] = 1;
                else dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                if (i==0 && j==0) dp[i][j] = 0;
                else if (i==0) dp[i][j] = dp[i][j-1];
                else if (j==0) dp[i][j] = dp[i-1][j];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    
    // for(int i =0;i<str1.length();i++){
    //     for(int j=0;j<str2.length();j++){
    //         cout << dp[i][j] << " "; 
    //     }
    //     cout << '\n';
    // }
    cout << dp[str1.length()][str2.length()];
    
    vector<char> vec;
    int i = str1.length();
    int j = str2.length();
    while(i >=0 || j>=0){
        if(dp[i][j] ==0) break;
        if(str1[i-1] == str2[j-1]){
            vec.push_back(str1[i-1]);
            i--; j--;
            continue;
        }
        dp[i-1][j] > dp[i][j-1] ? i-- : j--;
    }
    
    if(vec.size() != 0){
        cout << '\n';
        for(int i = vec.size()-1; i>=0;i--){
            cout << vec[i];
        }   
    }
    
    return 0;
}