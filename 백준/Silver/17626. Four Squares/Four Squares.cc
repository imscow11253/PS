#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long n;
    cin >>n;
    
    for(int i =1;i<=224;i++){
        if(i*i == n){
            cout << 1; return 0;
        }
    }
    
    for(int i=1;i<=224;i++){
        for(int j=i;j<=224;j++){
            if(i*i + j*j == n){
                cout << 2; return 0;
            }
        }
    }
    
    for(int i=1;i<=224;i++){
        for(int j=i;j<=224;j++){
            for(int k=j;k<=224;k++){
                if(i*i + j*j + k*k == n){
                    cout << 3; return 0;
                }   
            }
        }
    }
    
    for(int i=1;i<=224;i++){
        for(int j=i;j<=224;j++){
            for(int k=j;k<=224;k++){
                for(int t= k;t<=224;t++){
                    if(i*i + j*j + k*k + t*t== n){
                        cout << 4; return 0;
                    }      
                }
            }
        }
    }
    
    return 0;
}