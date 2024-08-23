#include <iostream>
#include <string>

using namespace std;

string str;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> str;
    
    int index=0;
    for(char a : str){
        cout << a;
        index++;
        if(index==10){ cout << '\n'; index=0;}
    }
    
    return 0;
}