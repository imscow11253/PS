#include <iostream>

using namespace std;

int n,k;
long long arr[200001];
long long sum[200001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> k;
    for(int i=1;i<=n;i++){
        cin >> arr[i];
        if(i==1){
            sum[i] = arr[i];
        }
        else sum[i] = sum[i-1] + arr[i];
    }
    
    long long result=0;
    long long temp;
    for(int i=1;i<=n;i++){
        if(i <= k){
            temp =0;
            temp += sum[i];
            temp += (k-i) * (long long)arr[i]; 
            if(result < temp) result = temp;
            // cout << i << " " << temp << '\n';
        }
        
        if(n-i+1 <= k){
            temp=0;
            temp += sum[n] - sum[i-1];
            temp += (k-(n-i+1)) * (long long)arr[i];
            if(result < temp) result = temp;
            // cout << i << " " << temp << '\n';
        }
    }
    
    cout << result;
    
    return 0;
}