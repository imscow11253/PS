#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n,m;
vector<pair<long long, long long>> vec;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    long long sta,en;
    for(int i =0;i<n;i++){
        cin >> sta >> en;
        if(sta > en){
            vec.push_back({en,sta});
        }
    }
    
    sort(vec.begin(), vec.end());
    
    long long result =0;
    if (!vec.empty()) {
        sta = vec[0].first;
        en = vec[0].second;
        for (int i = 1; i < vec.size(); i++) {
            if (vec[i].first > en) {
                result += 2 * (en - sta);
                sta = vec[i].first;
                en = vec[i].second;
            } else {
                en = max(en, vec[i].second);
            }
        }
        result += 2 * (en - sta);
    }
    
    cout << result + m;
    
    return 0;
}