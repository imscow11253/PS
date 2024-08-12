#include <iostream>
#include <climits>

using namespace std;

int n, t;
int start[50] ={};
int intervel[50] ={};
int num[50] ={};

int result = INT_MAX;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> t;
    for(int i =0;i<n;i++){
        cin >> start[i] >> intervel[i] >> num[i];
    }
    
    for(int i =0;i<n;i++){
        int idx = start[i];
        for(int j=0;j<num[i];j++){
            if(idx >= t){
                if(idx-t < result) result = idx-t;
                break;
            }
            idx+=intervel[i];
        }
    }
    
    if(result == INT_MAX) cout << -1;
    else cout << result;
    
    return 0;
}