#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<pair<int,int>> vec;
int arr[1001]={};

bool compare(pair<int,int> a, pair<int,int> b){
    return a.second > b.second;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    int a,b;
    int n_temp = n;
    while(n--){
        cin >> a >>b;
        vec.push_back({a,b});
    }
    
    sort(vec.begin(),vec.end(), compare);
    
    int cnt=0;
    for(auto j : vec){
        for(int i =j.first;i>=1; i--){
            if(arr[i] ==0){
                // cout << j.first << " " << j.second << " " << i << '\n';
                arr[i] =1;
                cnt += j.second;
                break;
            }
        }
    }
    
    cout << cnt;
    
    return 0;
}