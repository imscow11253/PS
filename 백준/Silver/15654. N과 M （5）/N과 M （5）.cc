#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n,m;
vector<int> arr;
bool visit[8] = {0,};
vector<int> print_vec;

void print_arr(){
    for(int a : print_vec) cout<< a << " ";
    cout << '\n';
}

void dfs(int num){
    if(num == m) {
        print_arr();
        return;
    }
    for(int i =0;i<n;i++){
        if(visit[i]) continue;
        visit[i] = true;
        print_vec.push_back(arr[i]);
        dfs(num+1);
        visit[i] = false;
        print_vec.erase(print_vec.end()-1);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    int temp;
    for(int i =0;i<n;i++){
        cin >> temp;
        arr.push_back(temp);
    }
    
    sort(arr.begin(), arr.end());
    
    dfs(0);
    
    return 0;
}