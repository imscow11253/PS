#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; string str;
    cin >> n;
    int k; cin >> k;
    vector<string> vec;
    while(k--){
        string st; cin >> st;
        vec.push_back(st);
    }
    n--;
    while(n--){
        int temp;
        cin >> temp;
        while(temp--){
            cin >> str;
        }
    }
    
    cout << vec.size() << '\n';
    for(auto a : vec) cout << a << "\n";
    
    return 0;
}