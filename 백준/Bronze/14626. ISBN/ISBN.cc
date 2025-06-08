#include <iostream>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string str;
    cin >> str;
    
    int sum=0;
    int weight=1;
    int cur = 1;
    int position;
    for(char a : str){
        if(a != '*'){
            sum += (a-'0') * weight;
        } 
        else{
            position = cur;
        }
        weight =  (weight == 1) ? 3 : 1;
        cur++;
    }
    
    int value;
    if(sum % 10 ==0) {cout << 0; return 0;}
    else {
        value = 10 - (sum % 10);
        // cout << sum << '\n';
        // cout << value << '\n';
        if(position % 2 ==0){
            for(int x=0; x<=9; ++x) {
                if((x*3)%10 == value) { cout << x; break; }
            }
        }
        else cout << value;
    }
    
    return 0;
}