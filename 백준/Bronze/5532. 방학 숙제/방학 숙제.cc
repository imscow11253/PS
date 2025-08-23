#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int l,A,B,a,b;
    
    cin >> l >> A >> B >> a >> b;
    
    int d,f;
    if(A%a != 0) d = A/a +1;
    else d = A/a;
    
    if(B%b != 0) f = B/b +1;
    else f = B/b;
    
    cout << l - max(d,f);
}