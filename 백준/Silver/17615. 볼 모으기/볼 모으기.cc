#include <iostream>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    string str;
    cin >> str;
    
    int result =INT_MAX;
    int temp=0;
    bool check = false;
    char first = str[0];
    for(int i =1;i<n;i++){
        if(str[i] != first) check = true;
        if(str[i] == first && check) temp++;
    }
    result = min(result, temp);
    // cout << result;
    
    temp=0;
    check = false;
    first = (str[0]=='R') ? 'B' : 'R';
    for(int i =n-2;i>=0;i--){
        if(str[i] == first) temp++;
    }
    result = min(result, temp);
    
    temp=0;
    check = false;
    first = str[n-1];
    for(int i =n-2;i>=0;i--){
        if(str[i] != first) check = true;
        if(str[i] == first && check) temp++;
    }
    result = min(result, temp);
    
    temp=0;
    check = false;
    first = (str[n-1]=='R') ? 'B' : 'R';
    for(int i =n-2;i>=0;i--){
        if(str[i] == first) temp++;
    }
    result = min(result, temp);
    
    cout << result;
    
    return 0;
}