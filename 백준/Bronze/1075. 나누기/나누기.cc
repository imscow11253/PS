#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,f;
    cin >> n >> f;
    
    int prefix = n /100;
    for(int i =0;i<=99;i++){
        if((prefix * 100 + i)%f == 0){
            if(i < 10) cout << "0" << i;
            else cout << i;
            break;
        }
    }
    
    return 0;
}