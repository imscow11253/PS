#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <climits>

using namespace std;

int c,n;
vector<int> chickens;
vector<pair<int,int>> cow;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> c >> n;
    int chick;
    while(c--){
        cin >> chick;
        chickens.push_back(chick);
    }
    sort(chickens.begin(), chickens.end());
    
    int sta, en;
    while(n--){
        cin >> sta >> en;
        cow.push_back({sta,en});
    }
    sort(cow.begin(), cow.end());
    
    bool visit[20000] ={0,};
    int result=0;
    for(int i =0;i<chickens.size();i++){
        int j=-1;
        pair<int,int> candi = {INT_MAX,INT_MAX};
        int index=-1;
        // cout << chickens[i] << '\n';
        while(j+1 < cow.size() && cow[j+1].first <= chickens[i]){
            ++j;
            if(cow[j].second < chickens[i]) continue;
            // cout << cow[j].first << " " << cow[j].second << '\n';
            if(candi.second > cow[j].second && !visit[j]){
                // cout << "candi : " << cow[j].first << " " << cow[j].second << '\n';
                candi = cow[j];
                index = j;
            }
        }
        if(index != -1){
            // cout << "selected : " << cow[index].first << " " << cow[index].second << '\n';
            visit[index] = true;
            result++;
        }
    }
    
    cout << result;
    return 0;
}