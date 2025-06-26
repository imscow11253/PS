#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int n;
int max_value = INT_MIN;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    vector<int> vec;
    
    int temp;
    for(int i = 0; i < n; i++){
        cin >> temp;
        auto it = lower_bound(vec.begin(), vec.end(), temp);
        if(it == vec.end()){
            vec.push_back(temp);
        } else {
            *it = temp;
        }
        max_value = max(max_value, (int)vec.size());
    }
    
    cout << max_value;
    
    return 0;
}