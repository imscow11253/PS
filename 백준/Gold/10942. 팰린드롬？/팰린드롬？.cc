#include <iostream>

using namespace std;

int n,m;
int arr[2001];
bool dp[2001][2001] = {0,};
bool check[2001][2001] = {0,};

bool dp_func(int sta, int en){
    if(check[sta][en]) return dp[sta][en];
    if(sta == en) {
        dp[sta][en] = true;
        check[sta][en] = true;
        return true;
    }
    
    if(arr[sta] != arr[en]) {
        dp[sta][en] = false;
        check[sta][en] = true;
        return false;
    }
    if(sta +1 <= en -1){
        bool isPalindrom = dp_func(sta+1, en-1);   
        if(!isPalindrom) {
            dp[sta][en] = false;
            check[sta][en] = true;
            return false;
        }
        dp[sta][en] = true;
        check[sta][en] = true;
        return true;
    }
    dp[sta][en] = true;
    check[sta][en] = true;
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    for(int i =1;i<=n;i++){
        cin >> arr[i];
    }
    
    cin >> m;
    int sta, en;
    while(m--){
        cin >> sta >> en;
        cout << dp_func(sta, en) << '\n';
    }
    
    return 0;
}