#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <deque>

using namespace std;

string str, boom;
stack<pair<char, int>> stk;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> str >> boom;
    for(char a : str){
        if(stk.empty()){
            if(a == boom[0]){
                stk.push({a, 1});
            }
            else stk.push({a,0});
        }
        else{
            if(a == boom[stk.top().second]){
                stk.push({a, stk.top().second+1});
            }
            else if(a == boom[0]){
                stk.push({a, 1});
            }
            else stk.push({a,0});
        }
        if(stk.top().second == boom.length()){
            for(int i =0;i<boom.length();i++) stk.pop();
        }
    }
    
    if(stk.empty()){
        cout << "FRULA";
        return 0;
    }
    
    vector<char> vec;
    while(!stk.empty()){
        vec.push_back(stk.top().first);
        stk.pop();
    }
    
    
    for(int i =vec.size()-1; i>=0; i--){
        cout << vec[i];
    }
    
    return 0;
}