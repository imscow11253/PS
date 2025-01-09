#include <iostream>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string a,b,c,d;
    cin >> a >> b >> c >> d;
    string ab = a+b;
    string cd = c+d;
    
    cout << stoull(ab) + stoull(cd);
    
    return 0;
}