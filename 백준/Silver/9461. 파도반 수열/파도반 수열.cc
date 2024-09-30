#include <iostream>

using namespace std;

long long int arr[101] ={};

long long int pado(int num){
    if(num <= 5) return arr[num];
    else{
        if(arr[num] != 0) return arr[num];
        else{
            arr[num] = pado(num-1) + pado(num-5);
            return arr[num];
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, temp;
    long long int re;
    cin >> N;
    arr[1] = 1; arr[2] = 1; arr[3]=1; arr[4] = 2; arr[5]=2; 
    while(N--){
        cin >> temp;
        re = pado(temp);
        cout << re << '\n';
    }
    
    return 0;
}