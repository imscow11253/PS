#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int n;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    string str, str2;
    cin >> str >> str2;
    
    string origin_str = str;
    
    int cnt =0;
    for(int i =1; i< str.length(); i++){
        if(str[i-1] != str2[i-1]){
            cnt += 1;
            str[i] = (str[i] == '0') ? '1' : '0';
            if(i != n-1) str[i+1] = (str[i+1] == '0') ? '1' : '0';
        }
    }
    int check = true;
    if(str[n-1] != str2[n-1]){
        check = false;
    }
    
    str = origin_str;
    str[0] = (str[0] == '0') ? '1' : '0';
    str[1] = (str[1] == '0') ? '1' : '0';
    int cnt2 =1;
    for(int i =1; i< str.length(); i++){
        if(str[i-1] != str2[i-1]){
            cnt2 += 1;
            str[i] = (str[i] == '0') ? '1' : '0';
            if(i != n-1) str[i+1] = (str[i+1] == '0') ? '1' : '0';
        }
    }
    int check2 = true;
    if(str[n-1] != str2[n-1]){
        check2 = false;
    }
    
    if(check == false && check2 == false) cout << -1;
    else if(check == false) cout << cnt2;
    else if(check2 == false) cout << cnt;
    else cout << min(cnt, cnt2);
    return 0;
}