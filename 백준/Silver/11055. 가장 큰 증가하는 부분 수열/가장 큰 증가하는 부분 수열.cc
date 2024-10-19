#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;

    int arr[1001];
    for(int i=1;i<=n;i++){
        cin >> arr[i];
    }
    
    int dp[1001]= {};
    dp[1] = arr[1];
    for(int i=2;i<=n;i++){
        int max_value=0;
        for(int j=1;j<i;j++){
            if(arr[i] > arr[j]) max_value = max(max_value, dp[j]);
        }
        dp[i] = max_value+arr[i];
    }
    
    int max_value=0;
    for(int i=1;i<=n;i++){
        max_value = max(max_value, dp[i]);
    }
    cout << max_value;
    
    return 0;
}