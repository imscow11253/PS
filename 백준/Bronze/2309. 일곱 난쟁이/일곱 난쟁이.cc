#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[9];


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int sum=0;
    for(int i=0;i<9;i++){
        cin >> arr[i];
        sum += arr[i];
    }
    
    int diff = sum -100;
    vector<int> vec;
    for(int i =0;i<9;i++){
        for(int j=i+1;j<9;j++){
            if(arr[i] + arr[j] == diff){
                for(int k=0;k<9;k++){
                    if(k == i || k == j) continue;
                    else vec.push_back(arr[k]);
                }
                sort(vec.begin(), vec.end());
                for(int a : vec) cout << a << '\n';
                exit(0);
            }
        }
    }
    
    
    
    return 0;
}