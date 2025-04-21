#include <iostream>
#include <map>
#include <string>

using namespace std;

int n,m;
map<string, string> memo;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    
    string site, password;
    for(int i =0;i<n;i++){
        cin >> site >> password;
        memo.insert({site, password});
    }
    
    for(int i =0;i<m;i++){
        cin >> site;
        cout << memo[site] << '\n';
    }
    
    
    return 0;
}