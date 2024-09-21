#include <iostream>
#include <algorithm>
#include <stdlib.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int mush;
    int sum=0;
    for(int i=0;i<10;i++){
        cin >> mush;
        sum += mush;
        if(sum >= 100){
            if(abs(sum-100) > abs((sum-mush)-100)) cout << sum-mush;
            else cout << sum;
            exit(0);
        }
    }
    
    cout << sum;
    
    return 0;
}