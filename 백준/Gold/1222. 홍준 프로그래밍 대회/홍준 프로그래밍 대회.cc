#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> vec;
int arr[2000001] = {0,};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    int max_value=0;
    while(n--){
        int temp; cin >> temp;
        vec.push_back(temp);
        max_value = max(max_value, temp);
    }
    
    for(const int& a : vec){
        if(a == 1) {arr[1]++; continue;}
        for(int i =1;i*i<= a; i++){
            if(a % i == 0){
                arr[i]++;
                if(a/i != i) arr[a/i]++;
            }
        }
    }
    
    // for(int i =1;i<=max_value;i++) cout << arr[i] << " " ;
    // cout << '\n';
    
    long long result =0;
    for(int i =1;i<=max_value;i++){
        if(arr[i] < 2) continue;
        result = max(result, (long long)i * arr[i]);
    }
    
    cout << result;
    
    return 0;
}