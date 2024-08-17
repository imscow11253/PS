#include <iostream>
#include <stack>

using namespace std;

int n;
int arr[1000000];
stack<pair<int,int>> stk;
int nge[1000000] = {};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    
    int index=0;
    for(int i=0;i<n;i++){
        if(stk.empty()) {
            stk.push({arr[i], index++});
        }
        else{
            if(stk.top().first >= arr[i]) {
                stk.push({arr[i], index++});
            }
            else{
                while(!stk.empty() && stk.top().first < arr[i]){
                    auto a = stk.top();
                    stk.pop();
                    nge[a.second] = arr[i];
                }
                stk.push({arr[i], index++});
            }
        }
        // for(int i =0;i<n;i++) cout << nge[i] << " "; cout << '\n';
    }
    
    for(int i=0;i<n;i++){
        if(nge[i] == 0) cout << -1 << " ";
        else cout << nge[i] << " "; 
    }
    
    return 0;
}