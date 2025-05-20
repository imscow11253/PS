#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <stdlib.h>

using namespace std;

int n;
vector<pair<int, int>> vec;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >>n;
    int temp;
    for(int i =0;i<n;i++){
        cin >> temp;
        if(temp < 0) vec.push_back({temp * -1, -1});
        else vec.push_back({temp, 1});
    }
    
    sort(vec.begin(), vec.end());
    
    int diff = INT_MAX;
    int a,b;
    for(int i =0;i<n-1;i++){
        int temp_a = vec[i].first * vec[i].second;
        int temp_b = vec[i+1].first * vec[i+1].second;
        if(abs(temp_a + temp_b) < diff){
            diff = abs(temp_a + temp_b);
            a = vec[i].first * vec[i].second;
            b = vec[i+1].first * vec[i+1].second;
        }
    }
     
    cout << min(a,b) << " " << max(a,b);
    
    
    return 0;
}