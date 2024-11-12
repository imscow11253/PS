#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int n;
int top[250000];
int bot[250000];
vector<pair<int,int>> vec;
int minv[250000];

bool compare(const pair<int,int> &a, const pair<int,int> &b){
    return a.first < b.first;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    int a ,b;
    for(int i =0;i<n;i++){
        cin >> top[i];
    }
    for(int i =0;i<n;i++){
        cin >> bot[i];
    }
    for(int i =0;i<n;i++){
        vec.push_back({top[i]-bot[i],i});
    }
    // for(auto a : vec){
    //     cout << a.first << ", " << a.second << '\n';
    // }
    sort(vec.begin(), vec.end());
    int minn = INT_MAX; int index=0;
    for(auto a : vec){
        // cout << a.first << ", " << a.second;
        minn = min(minn, a.second);
        minv[index++] = minn; 
        // cout << ", " << minv[index-1] << '\n';
    }
    int wn,w;
    cin >> wn;
    while(wn--){
        cin >> w;
        int temp = lower_bound(vec.begin(),vec.end(),pair<int,int>(w,0),compare)-vec.begin();
        if(temp==0) cout << n <<'\n';
        else cout << minv[temp-1] << '\n';
    }
    
    return 0;
}