#include <iostream>

using namespace std;

int a , b, c;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> a >> b >> c;
    
    b += c;
    if(b < 60) cout << a << " " << b;
    else{
        int hour = b / 60;
        b = b % 60;
        
        a += hour;
        if(a < 24) cout << a << " " << b;
        else{
            while(a>=24) a -= 24;
            cout << a << " " << b;
        }
    }
    
    return 0;
}