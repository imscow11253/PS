#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int n,k;
vector<pair<int,int>> jewels;
multiset<int> capacity;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> k;
    int weight, price;
    for(int i =0;i<n;i++){
        cin >> weight >> price;
        jewels.push_back({price, weight});
    }
    
    sort(jewels.begin(), jewels.end(), greater<>());
    
    for(int i =0;i<k;i++){
        cin >> weight;
        capacity.insert(weight);
    }
    
    long long result =0;
    for(auto a : jewels){
        int v = a.first;
        int w = a.second;
        
        auto it = capacity.lower_bound(w);
        if(it != capacity.end()){
            result += v;
            capacity.erase(it);
        }
    }
    
    cout << result;
    
    return 0;
}