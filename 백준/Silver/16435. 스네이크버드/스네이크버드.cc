#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, l;
vector<int> vec;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> l;
    
    int temp;
    while(n--){
        cin >> temp;
        vec.push_back(temp);
    }
    
    sort(vec.begin(), vec.end());
    
    for(auto a : vec){
        if(a <= l) l++;
    }
    
    cout << l;
    return 0;
}