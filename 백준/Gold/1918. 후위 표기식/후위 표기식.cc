#include <iostream>
#include <stack>
#include <string>

using namespace std;

string str;
stack<char> stk;

void oper(){
    for(int i=0;i<str.length();i++){ 
        if(str[i] >= 'A') cout << str[i];
        else {
            if(stk.empty()) stk.push(str[i]);
            else if(str[i] == '(') stk.push(str[i]);
            else if(str[i] == '+' || str[i] == '-'){
                while(!stk.empty() && stk.top() != '('){
                    cout << stk.top();
                    stk.pop();
                }
                stk.push(str[i]);
            }
            else if(str[i] == '*' || str[i] == '/'){
                while(!stk.empty() && stk.top() != '+' && stk.top() != '-' && stk.top() != '('){
                    cout << stk.top();
                    stk.pop();
                }
                stk.push(str[i]);
            }
            else if(str[i] == ')'){
                while(stk.top() != '('){
                    cout << stk.top();
                    stk.pop();
                }
                stk.pop();
            }
        }
    }
    while(!stk.empty()){
        cout << stk.top();
        stk.pop();
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> str;
    
    oper();

    return 0;
}