#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    vector<pair<double long, int>> vec;
    
    double long t,s;
    for(int i=0;i<n;i++){
        cin >> t >> s;
        vec.push_back({t/s, i+1});
    }
    
    sort(vec.begin(), vec.end());
    
    for(auto a : vec){
        cout << a.second<< " ";
    }
    
    return 0;
}