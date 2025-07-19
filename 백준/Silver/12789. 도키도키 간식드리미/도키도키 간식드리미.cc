#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    queue<int> qu;
    int temp;
    for(int i =0;i<n;i++){
        cin >> temp;
        qu.push(temp);
    }
    
    int order =1;
    stack<int> stk;
    while(!qu.empty()){
        int next = qu.front();
        qu.pop();
        
        while(!stk.empty() && stk.top() == order){
            stk.pop();
            order++;
        }
        if(next == order){
            order++;
            continue;
        }
        stk.push(next);
    }
    
    while(!stk.empty() && stk.top() == order){
        stk.pop();
        order++;
    }
    
    if(stk.empty()) cout << "Nice";
    else cout << "Sad";
    
    return 0;
}