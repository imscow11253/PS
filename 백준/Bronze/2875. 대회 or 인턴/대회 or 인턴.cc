#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,m,k;
    cin >> n >> m >> k;
    
    int index = m;
    while(2*index > n || (n+m)-(3*index) < k){
        index--;
    }
    
    cout << index;
    
    return 0;
}