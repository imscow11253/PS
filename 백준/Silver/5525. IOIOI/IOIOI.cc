#include <iostream>
#include <string>

using namespace std;

int n,m;
int arr[1000000];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    string str;
    cin >> str;
    
    arr[m-1]=0;
    arr[m-2]=0;
    for(int i = str.length()-3; i>= 0 ;i--){
        if(str[i+1] == 'O' && str[i+2] == 'I' && str[i] == 'I'){
            arr[i] = arr[i+2] + 1;
        }
        else arr[i] =0;
    }
    
    int result=0;
    for(int i =0;i<m;i++){
        if(n <= arr[i]) result++;
    }
    
    cout << result;
    return 0;
}