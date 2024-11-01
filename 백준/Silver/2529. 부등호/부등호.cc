#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int arr[10] = {0,1,2,3,4,5,6,7,8,9};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    string str;
    getline(cin, str);
    getline(cin, str);
    
    int index=9;
    for(int i =0;i<str.length();i++){
        if(str[i] == ' ') continue;
        if(str[i] == '>'){
            cout << arr[index];
            index--;
        }
        else {
            int num=0;
            while(str[i] == '<' || str[i] ==' '){
                if(str[i] == '<') num++;
                i++;
            }
            
            for(int j=0;j<num+1;j++){
                cout << arr[index-(num-j)];
            }
            index -= num+1;
        }
    }
    if(9-index != n+1)cout << arr[index] << '\n';
    else cout << '\n';
    
    index=0;
    for(int i =0;i<str.length();i++){
        if(str[i] == ' ') continue;
        if(str[i] == '<'){
            cout << arr[index];
            index++;
        }
        else {
            int num=0;
            while(str[i] == '>' || str[i] ==' '){
                if(str[i] == '>') num++;
                i++;
            }
            
            for(int j=0;j<num+1;j++){
                cout << arr[index+(num-j)];
            }
            index += num+1;
        }
    }
    if(index != n+1)cout << arr[index] << '\n';
    
    return 0;
}