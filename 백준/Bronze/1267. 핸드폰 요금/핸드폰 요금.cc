#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    int t;
    int y=0,m=0;
    while(n--){
        cin >> t;
        y += (t/30+1) * 10;
        m += (t/60+1) * 15;
    }
    
    if(y < m) cout << "Y " << y;
    else if(m< y) cout << "M " << m;
    else cout << "Y M " << y;
    
    return 0;
}