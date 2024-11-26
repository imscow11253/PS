#include <iostream>

using namespace std;

int n;
int arr[200000];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    if(n==2) {cout << 1;return 0;}
    if(n==3) {cout << 3;return 0;}
    else{
        cout << (n-2)*2 + n;
    }
    
    return 0;
}