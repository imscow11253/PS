#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string str;
    cin >> str;
    
    for(char a : str){
        if(a <= 'Z' && a >= 'A') cout << (char)(a+32);
        else cout << (char)(a-32);
    }
    
    return 0;
}