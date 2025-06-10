#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int n;
map<char, vector<string>> mp;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    string str;
    while(n--){
        cin >> str;
        if(mp.find(str[0]) == mp.end()){
            vector<string> temp;
            temp.push_back(str);
            mp.insert({str[0], temp});
        }
        else{
            mp[str[0]].push_back(str);
        }
    }
    
    int check=1;
    for(auto a : mp){
        if(a.second.size() >= 5) {
            cout << a.first;
            check=0;
        }
    }
    if(check) cout << "PREDAJA";
    
    return 0;
}