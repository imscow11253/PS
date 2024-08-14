#include <iostream>

using namespace std;

int n;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;

    if(n==3) cout << -1;
    else if(n%2 ==0){
        cout << n/2 << '\n';
        for(int i=1;i<n/2;i++) cout << i << '\n';
        for(int i=n/2+2;i<=n;i++) cout << i << '\n';
        cout << n/2+1 << '\n';
    }
    else{
        cout << n-2 << '\n';
        for(int i=1;i<n-2;i++) cout << i << '\n';
        cout << n << '\n' << n-1 << '\n';
    }
    
    return 0;
}