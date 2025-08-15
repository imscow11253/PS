#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    int result=0;
    int money = 1000 - n;
    if(money / 500 > 0){
        result += money /500;
        money %= 500;
    }
    if(money / 100 > 0){
        result += money /100;
        money %= 100;
    }
    if(money / 50 > 0){
        result += money /50;
        money %= 50;
    }
    if(money / 10 > 0){
        result += money /10;
        money %= 10;
    }
    if(money / 5 > 0){
        result += money /5;
        money %= 5;
    }
    if(money / 1 > 0){
        result += money /1;
        money %= 1;
    }
    cout << result;
    
    return 0;
}