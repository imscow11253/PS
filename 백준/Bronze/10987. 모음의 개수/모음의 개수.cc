#include <iostream>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string str;
    cin >> str;
    
    int result=0;
    for(char a : str){
        if(a == 'a' || a == 'e' || a == 'o' || a == 'u' || a == 'i') result++;
    } 
    
    cout << result;
    
    return 0;
}