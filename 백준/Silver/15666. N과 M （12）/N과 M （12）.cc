#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int n,m;
int arr[8];
vector<int> vec;
set<vector<int>> st;

void select(int index){
    if(vec.size() > m) return;
    if(vec.size() == m && st.find(vec) == st.end()){
        for(int a : vec) cout << a << " ";
        cout << '\n';
        st.insert(vec);
        return ;
    }
    for(int i =index;i<n;i++){
        vec.push_back(arr[i]);
        select(i);
        vec.erase(vec.end()-1);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    for(int i=0;i<n;i++) cin >> arr[i];
    
    sort(arr, arr+n);
    // for(int a : arr) cout << a << " "; cout << '\n';
    select(0);
    
    return 0;
}