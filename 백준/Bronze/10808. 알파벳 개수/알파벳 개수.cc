#include <iostream>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string str;
    cin >> str;
    
    int arr[26]={};
    for(char a : str){
        arr[a-'a']++;
    }
    
    for(int a : arr) cout << a << " ";
    
    return 0;
}