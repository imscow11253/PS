#include <iostream>
#include <string>

using namespace std;

int n,m;
int arr[50][50] = {0,};
int brr[50][50]= {0,};

void change(int row, int col){
    if(row +2 >= n || col+2 >=m){
        return;
    }
    for(int i =0;i<3;i++){
        for(int j=0;j<3;j++){
            arr[row+i][col+j] =  (arr[row+i][col+j] == 1) ? 0 : 1;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >>m;
    
    string str;
    for(int i =0;i<n;i++){
        cin >> str;
        for(int j=0;j<m;j++){
            arr[i][j] = str[j]-48;
        }
    }
    for(int i =0;i<n;i++){
        cin >> str;
        for(int j=0;j<m;j++){
            brr[i][j] = str[j]-48;
        }
    }
    
    int count=0;
    for(int i =0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j] != brr[i][j]) {change(i,j); count++;}
        }
    }
    
    for(int i =0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j] != brr[i][j]) {
                cout << -1; return 0;
            }
            
        }
    }
    cout << count;
    
    return 0;
}