#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int l,n;
vector<int> vec;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> l;
    int temp;
    for(int i =0;i<l;i++){
        cin >> temp;
        vec.push_back(temp);
    }
    sort(vec.begin(), vec.end());
    
    cin >> n;
    
    auto it = lower_bound(vec.begin(), vec.end(), n);
    if(n == *it){
        cout << 0;
        return 0;
    }
    
    int low = n - *(it-1) -1;
    int high = *it - n - 1;
    
    long long result =0;
    result += low * high;
    result += low + high;
    
    cout << result;
    
    return 0;
}