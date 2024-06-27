#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long double a,b;
    cin >> a >> b;
    
    cout.precision(13);
    cout << (double)(a /b);

    return 0;
}