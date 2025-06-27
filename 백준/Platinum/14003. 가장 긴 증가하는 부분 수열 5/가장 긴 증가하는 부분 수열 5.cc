#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;

    int arr[1000000];
    vector<int> lis;
    int next;
    int max_value=0;
    int dp[1000000];
    for(int i =0;i<n;i++){
        cin >> next;
        arr[i] = next;
        auto it = lower_bound(lis.begin(), lis.end(), next);
        if(it == lis.end()) {
            lis.push_back(next);
            dp[i] = lis.size();
        }
        else {
            *it = next;
            dp[i] = (int)(it - lis.begin() +1);
        }
        max_value = max(max_value, (int)lis.size());
    }
    
    cout << max_value << '\n';
    
    vector<int> temp;
    for(int i=n-1; i>=0;i--){
        if(dp[i] == max_value){
            temp.push_back(arr[i]);
            max_value--;
        }
    }
    
    for(int i =temp.size()-1; i>=0 ; i--) cout << temp[i] << " ";
    
    return 0;
}