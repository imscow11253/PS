#include <iostream>
#include <stack>

using namespace std;

stack<pair<int,int>> stk;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    pair<int,int> current= {0,0};
    int a, b,c;
    
    int result =0;
    while(t--){
        cin >> a;
        if(current.first != 0 && current.second == 0){
            result += current.first;
            if(stk.size() != 0){
                current = stk.top();
                stk.pop();
            } 
        }
        if(a){
            cin >> b >> c;
            if(current.first != 0) stk.push(current);
            current = {b,c};
        }
        current.second--;
        // cout << "=====================\n";
        // cout << "current = " << current.first << " " << current.second << '\n';
        // if(stk.size()!=0) cout << stk.top().first << " " << stk.top().second << '\n';
    }
    
    if(current.second == 0){
        result += current.first;
    }
    
    cout << result;
    
    return 0;
}