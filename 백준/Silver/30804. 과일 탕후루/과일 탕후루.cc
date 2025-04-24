#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int n;
int dp[2][200001] = {0,};
set<int> st[200001];
int arr[200001] = {0,};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    for(int i =1;i<=n;i++){
        cin >> arr[i];
    }
    
    dp[0][1] = 0;
    dp[1][1] = 1;
    st[1].insert(arr[1]);
    
    int max_value= 1;
    for(int i =2;i<=n;i++){
        if(arr[i-1] == arr[i]){
            dp[0][i] = dp[0][i-1];
            dp[1][i] = dp[1][i-1]+1;
            st[i] = st[i-1];
            max_value = max(max_value, dp[1][i]);
        }
        else if(st[i-1].find(arr[i]) != st[i-1].end()){
            dp[0][i] = i;
            dp[1][i] = dp[1][i-1]+1;
            st[i] = st[i-1];
            max_value = max(max_value, dp[1][i]);
        }
        else if(st[i-1].size() == 1){
            dp[0][i] = i;
            dp[1][i] = dp[1][i-1]+1;
            st[i] = st[i-1];
            st[i].insert(arr[i]);
            max_value = max(max_value, dp[1][i]);
        }
        else{
            dp[0][i] = i;
            dp[1][i] = i - (dp[0][i-1]-1);
            st[i] = {arr[i], arr[i-1]};
            max_value = max(max_value, dp[1][i]);
        }
        
        // for(int j=1;j<=n;j++){
        //     cout << dp[0][j] << " ";
        // }cout <<'\n';
        // for(int j=1;j<=n;j++){
        //     cout << dp[1][j] << " ";
        // }cout <<'\n';
        // cout << "=========\n";
    }
    
    cout << max_value;
    
    return 0;
}