#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <string>

using namespace std;

int arr[10];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    if(n< 10) {cout << n;exit(0);}
    
    
    int result = 9;
    for(int i=10;i<=n;i++){
        string str = to_string(i);
        int diff = (str[1]-'0') - (str[0]-'0');
        int check=1;
        for(int j=2;j<str.length();j++){
            if((str[j]-'0')-(str[j-1]-'0') != diff){
                check=0; break;
            }
        }
        if(check) result++;
    }
    
    cout << result;
    
    return 0;
}