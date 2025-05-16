#include <iostream>
#include <set>
#include <map>
#include <vector>

using namespace std;

int n, m;
int set_id[1000001];
map<int,vector<int>> mp;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    for(int i=0;i<=n;i++){
        set_id[i] = i;
        vector<int> vec;
        vec.push_back(i);
        mp.insert({i, vec});
    }
    
    int oper, a, b;
    for(int i =0;i<m;i++){
        cin >> oper >> a >> b;
        // if(set_id[a] == -1 || set_id[b] == -1) continue;
        switch(oper){
            case 0:
                if(set_id[a] != set_id[b]){
                    // cout << "im working\n";
                    if(mp[set_id[a]].size() > mp[set_id[b]].size()){
                        for(int candi : mp[set_id[b]]){
                            mp[set_id[a]].push_back(candi);
                            set_id[candi] = set_id[a];
                        }   
                        mp.erase(b);
                    }
                    else{
                        for(int candi : mp[set_id[a]]){
                            mp[set_id[b]].push_back(candi);
                            set_id[candi] = set_id[b];
                        }   
                        mp.erase(a);
                    }
                }
                break;
            case 1:
                if(set_id[a] == set_id[b]) cout << "YES\n";
                else cout << "NO\n";
                break;
        }
        // cout << "set Id \n";
        // for(int j=0;j<=n;j++) cout << set_id[j] << " ";
        // cout << '\n';
        // for(auto p : mp){
        //     cout << p.first << " : ";
        //     for(int t : p.second){
        //         cout << t << ", ";
        //     }
        //     cout << '\n';
        // }
    }
    
    return 0;
}