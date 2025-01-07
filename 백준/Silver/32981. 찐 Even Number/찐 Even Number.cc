#include <iostream>

using namespace std;

int divide = 1000000007;
int arr[10000001] = {};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    arr[1] =5; arr[2] =20;
    for(int i =3;i<=10000000;i++){
        arr[i] = ((long long)arr[i-1] * 5)%divide;
    }    
    int temp;
    while(n--){
        cin >> temp;
        cout << arr[temp] << '\n';
    }
    
    return 0;
}