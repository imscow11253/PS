#include <iostream>
#include <stack>

using namespace std;

int n;
stack<int> stk;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    
    int temp;
    while(n--){
        cin >> temp;
        
        int x;
        switch(temp){
            case 1:
                cin >> x;
                stk.push(x);
                break;
            case 2:
                if(stk.empty()) {cout << -1 << '\n';}
                else{cout << stk.top()<< '\n'; stk.pop();}
                break;
            case 3:
                cout << stk.size() << '\n';
                break;
            case 4:
                if(stk.empty()) cout << 1 << '\n';
                else cout << 0 << '\n';
                break;
            case 5:
                if(stk.empty()) {cout << -1 << '\n';}
                else{cout << stk.top()<< '\n';}
                break;
        }
    }
    
    return 0;
}