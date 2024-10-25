#include <iostream>
#include <cmath>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    if(n==1) cout << 8+2;
    else if(n==2) cout << 8+1+2;
    else{
        if(ceil(log2(n)) == floor(log2(n))){
            cout << 8+log2(n)+2;
        }
        else{
            cout << 8+floor(log2(n))+2;
        }
    }
    
    return 0;
}