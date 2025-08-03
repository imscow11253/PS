#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<int> lis;
    int temp;
    for(int i =0;i<n;i++){
        cin >> temp;
        auto it = lower_bound(lis.begin(), lis.end(), temp);
        if(it == lis.end()) lis.push_back(temp);
        else *it = temp;
    }
    cout << n - lis.size();
    
    
    return 0;
}