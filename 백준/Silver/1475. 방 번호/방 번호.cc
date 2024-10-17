#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int arr[9]={};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string n;
    cin >> n;
    
    for(char a : n){
        if(a -'0' == 9)  arr[6]++;
        else arr[a-'0']++;
    }
    
    int result =0;
    for(int i =0;i<9;i++){
        if(i==6) result = max(result, arr[i] - arr[i]/2);
        else result = max(result, arr[i]);
    }
    
    cout << result;
    
    return 0;
}