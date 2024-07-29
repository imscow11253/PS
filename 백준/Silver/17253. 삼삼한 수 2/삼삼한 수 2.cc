#include <iostream>

using namespace std;

long long n;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    
    if(n ==0) {cout << "NO"; exit(0);}
    while(n >0){
        if(n%3 > 1){
            cout << "NO"; exit(0);
        }
        n /= 3;
    }
    cout << "YES" ;
    
    return 0;
}