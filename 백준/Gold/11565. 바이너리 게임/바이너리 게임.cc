#include <iostream>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string a,b;
    cin >>a >>b;
    
    int a_one =0;
    int b_one =0;
    for(char i : a){
        if(i == '1') a_one++;
    }
    for(char i : b){
        if(i == '1') b_one++;
    }
    
    if(a_one %2 ==0){
        if(a_one >= b_one) cout << "VICTORY";
        else cout << "DEFEAT";
    }
    else{
        if(a_one+1 >= b_one) cout << "VICTORY";
        else cout << "DEFEAT";
    }
    
    return 0;
}