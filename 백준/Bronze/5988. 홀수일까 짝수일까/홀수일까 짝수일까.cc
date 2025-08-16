#include <iostream>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    while(n--){
        string str;
        cin >> str;
        if(((int)str[str.length()-1])%2 ==0 ) cout << "even\n";
        else cout << "odd\n";
    }
    
    return 0;
}
