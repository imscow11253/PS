#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool str_index[100] ={};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string str;
    cin >> str;
    
    int cnt = str.length();
    vector<pair<string,int>> vec;
    while(cnt--){
        for(int j=0;j<str.length();j++){
            if(!str_index[j]){
                str_index[j] =true;
                string a = "";
                for(int i=0;i<str.length();i++){
                    if(str_index[i]) a+=str[i];
                }
                vec.push_back({a,j});
                str_index[j]=false;
            }
        }
        sort(vec.begin(), vec.end());
        cout << vec[0].first << '\n';
        str_index[vec[0].second] = true;
        vec.clear();
    }
    
    return 0;
}