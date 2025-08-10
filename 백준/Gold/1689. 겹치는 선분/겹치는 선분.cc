#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int n;
vector<pair<int,int>> vec;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    int sta,en;
    for(int i =0;i<n;i++){
        cin >> sta >> en;
        vec.push_back({sta, 1});
        vec.push_back({en, 0});
    }
    sort(vec.begin(), vec.end());
    
    stack<int> stk; 
    int result=0;
    for(const auto &a : vec){
        if(a.second == 1) {
            stk.push(a.first);
            result = max(result, (int)stk.size());
        }
        else{
            stk.pop();
        }
    }
    cout << result;
    
    return 0;
}