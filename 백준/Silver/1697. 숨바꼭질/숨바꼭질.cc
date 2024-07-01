#include <iostream>
#include <queue>

using namespace std;

int n,k;
int cnt =0;
queue<pair<int, int>> qu;

int arr[100001] ={};

void travel(){
    
    while(!qu.empty()){
        auto cdt = qu.front();
        qu.pop();
        
        if(cdt.first == k) {
            cout << cdt.second;
            break;
        }
        
        if(cdt.first+1 <= 100000 && !arr[cdt.first+1]) {
            qu.push({cdt.first+1, cdt.second+1});
            arr[cdt.first+1] = cdt.second+1;
        }
        if(cdt.first-1 >= 0 && !arr[cdt.first-1]) {
            qu.push({cdt.first-1, cdt.second+1});
            arr[cdt.first-1] = cdt.second+1;
        }
        if(cdt.first*2 <= 100000 && !arr[cdt.first*2]) {
            qu.push({2*cdt.first, cdt.second+1});
            arr[cdt.first*2] = cdt.second+1;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> k;
    
    if(n >= k) cout << n-k;
    else {
        qu.push({n,cnt});
        travel();
    }
    
    return 0;
}