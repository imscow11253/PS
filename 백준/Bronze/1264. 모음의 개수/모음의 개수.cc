#include <iostream>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string str = "";
    while(str != "#"){
        getline(cin, str);
        if(str == "#") break;
        int result =0;
        // cout << str << '\n';
        for(char a : str){
            if(a == 'a' || a == 'A' || a == 'e' || a == 'E' || a == 'i' || a == 'I' || a == 'o' || a == 'O' || a == 'u' || a == 'U') result++;
        }
        cout << result << '\n';
    }
    
    return 0;
}