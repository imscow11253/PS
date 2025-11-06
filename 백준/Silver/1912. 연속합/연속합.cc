#include <iostream>
#include <cmath>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    int arr[N];
    int DP[N];
    for(int i =0;i<N;i++) cin >> arr[i];
    
    int max = arr[0];
    DP[0] = arr[0];
    
    for(int i=1;i<N;i++){
        int temp = DP[i-1]+arr[i];
        if(temp>arr[i]) DP[i]=temp;
        else DP[i]=arr[i];
        if(max<DP[i]) max = DP[i];
    }
    cout << max;
    
    return 0;
}