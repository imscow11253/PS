#include <iostream>
#include <string>
#include <map>

using namespace std;

int n;
map<string, int> mp;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    string str;
    for(int i=0;i<n;i++){
        cin >> str;
        mp.insert({str,0});
    }
    
    for(int i =0;i<n-1;i++){
        cin >> str;
        mp[str]++;
    }
    
    for(auto a : mp){
        if(a.second == 0) cout << a.first;
    }
    
    return 0;
}