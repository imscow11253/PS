#include <iostream>

using namespace std;

long long diff = 9*17;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long n;
    cin >> n;
    
    for(long long i = n-diff; i<n;i++){
        long long temp = i;
        long long a = i;
        while(a){
            temp += a % 10;
            a /= 10;
        } 
        if(temp == n) {cout << i; return 0;}
    }
    cout << 0;
    
    return 0;
}