#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string s){
    int l=0, r=s.size()-1;
    while(l<r){
        if(s[l]!=s[r]) return false;
        l++; r--;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    for(int i=0;i<s.size();i++){
        if(isPalindrome(s.substr(i))){
            cout << s.size() + i;
            return 0;
        }
    }
}