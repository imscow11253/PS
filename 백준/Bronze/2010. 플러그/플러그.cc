#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    int temp, sum=0;
    for(int i =0;i<n;i++){
        cin >> temp;
        if(i == n-1) sum += temp;
        else sum += temp-1;
    }
    cout << sum;
    
    return 0;
}