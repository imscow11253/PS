#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    long long int arr[10] = {0,1,1,1,1,1,1,1,1,1};
    long long int arr2[10];
    long long int DP[N] = {}; DP[0]=9;
    
    for(int i=1;i<N;i++){
        DP[i] += arr[0]; DP[i] += arr[9];
        arr2[0] =arr[1]%1000000000; arr2[9]=arr[8]%1000000000;
        for(int j=1;j<9;j++) {
            DP[i] += arr[j]*2;
            arr2[j] = (arr[j+1] + arr[j-1])%1000000000;
        }
        for(int j=0;j<10;j++) arr[j] = arr2[j];
    }
    cout << DP[N-1]%1000000000;
    
    return 0;
}