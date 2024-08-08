#include <iostream>
#include <stack>

using namespace std;

int n;
stack<int> stk;
long long cnt=0;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    
    int temp;
    while(n--){
        cin >> temp;
        
        if(stk.empty()) {
            stk.push(temp);
            continue;
        }
        
        while(!stk.empty() && stk.top() <= temp) stk.pop();
        cnt += stk.size();
        
        stk.push(temp);
    }
    
    cout <<cnt;
    
    return 0;
}