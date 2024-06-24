#include <iostream>

using namespace std;

void func(int** arr, int** temp, int** index, long long int B,int &N){
    if(B!=1){
        
        func(arr,temp,index,B/2,N);
        
        for(int i =0;i<N;i++){
            for(int j=0;j<N;j++){
                int sum=0;
                for(int k=0;k<N;k++) sum += arr[i][k] * arr[k][j];
                temp[i][j] = sum;
            }
        }
        for(int i =0;i<N;i++){
            for(int j=0;j<N;j++) arr[i][j] = temp[i][j]%1000;
        }
        
        if(B%2 == 1) {
            for(int i =0;i<N;i++){
                for(int j=0;j<N;j++){
                    int sum=0;
                    for(int k=0;k<N;k++) sum += arr[i][k] * index[k][j];
                    temp[i][j] = sum;
                }
            }
            for(int i =0;i<N;i++){
                for(int j=0;j<N;j++) arr[i][j] = temp[i][j]%1000;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    long long int B;
    cin >> N >> B;
    
    int** arr = new int*[N];
    int** temp = new int*[N];
    int** index = new int*[N];
    for(int i =0;i<N;i++){
        arr[i] = new int[N];
        temp[i] = new int[N];
        index[i] = new int[N];
        for(int j=0;j<N;j++){
            cin >> arr[i][j];
            index[i][j] = arr[i][j];
        }
    }
    
    func(arr,temp,index, B,N);
    
    for(int i =0;i<N;i++){
        for(int j=0;j<N;j++) cout << arr[i][j]%1000 << " ";
        cout << '\n';
    }
    
    for(int i=0;i<N;i++){
        delete[] arr[i];
        delete[] temp[i];
        delete[] index[i];
    }
    delete[] arr;
    delete[] temp;
    delete[] index;

    return 0;
}