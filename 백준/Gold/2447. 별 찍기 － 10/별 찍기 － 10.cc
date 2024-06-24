#include <iostream>

using namespace std;

void checkBlank(char** arr, int size, int n){
    if(n!=1){
        for(int i =n/3; i<size; i+=n){
            for(int j=n/3; j<size; j+=n){
                for(int k=i; k<i+n/3; k++){
                    for(int h=j; h<j+n/3; h++){
                        arr[k][h] = ' ';
                    }
                }
            }
        }
        checkBlank(arr, size, n/3);
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    char** arr = new char*[N];
    for(int i =0;i<N;i++) {
        arr[i] = new char[N];
        for(int j=0;j<N;j++) arr[i][j] = '*';
    }
    checkBlank(arr,N, N);
    
    for(int i=0;i<N;i++){
        for(int j=0; j<N; j++) cout << arr[i][j];
        cout << '\n';
    }
    
    for(int i =0;i<N;i++) delete[] arr[i];
    delete[] arr;
    return 0;
}