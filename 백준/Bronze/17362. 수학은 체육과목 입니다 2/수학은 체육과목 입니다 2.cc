#include <iostream>

using namespace std;

int arr[8] = {1,2,3,4,5,4,3,2};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    n %= 8;
    if(n ==0) cout << arr[7];
    else cout << arr[n-1];
    
    return 0;
}