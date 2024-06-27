#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string str;
    getline(cin, str);
    
    int check =0, cnt =0;
    for(char a : str){
        //cout << a << '\n';
        if(a == ' '){
            if(check == 1){
                check =0;
                cnt++;
            }
        }
        else{
            check=1;
        }
    }
    
    if(str[str.length()-1] != ' ') cnt++;

    cout << cnt ;
    return 0;
}