#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    vector<int> vec;
    int temp;
    while(t--){
        for(int i =0;i<10;i++){
            cin >> temp;
            vec.push_back(temp);
        }
        sort(vec.begin(), vec.end());
        cout << vec[7] << '\n';
        vec.clear();
    }
    
    return 0;
}