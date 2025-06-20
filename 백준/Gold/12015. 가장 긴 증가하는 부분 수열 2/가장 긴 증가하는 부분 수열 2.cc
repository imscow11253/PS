#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n), lis;
    for(int i=0; i<n; i++) cin >> arr[i];
    for(int i=0; i<n; i++){
        auto it = lower_bound(lis.begin(), lis.end(), arr[i]);
        if(it == lis.end()) lis.push_back(arr[i]);
        else *it = arr[i];
    }
    cout << lis.size();
}