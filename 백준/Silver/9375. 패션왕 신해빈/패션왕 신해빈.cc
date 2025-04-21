#include <iostream>
#include <map>
#include <string>

using namespace std;

int n;
map<string, int> cloth;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    int m;
    while(n--){
        cin >> m;
        string name, type;
        cloth.clear();
        while(m--){
            cin >> name >> type;
            if(cloth.find(type) != cloth.end()) cloth[type]++;
            else cloth.insert({type, 1});
        }
        if(cloth.size() ==0 ) cout << 0 << '\n';
        else {
            int result=1;
            for(auto a : cloth){
                result *= (a.second + 1);
            }   
            cout << result -1 << '\n';
        }
    }
    
    return 0;
}