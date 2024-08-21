#include <iostream>

using namespace std;

int input[8];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int temp;
    for(int i =0;i<8;i++){
        cin >> input[i];
    }
    
    int check=0;
    for(int i =1;i<=8;i++){
        // cout << input[i-1] << " " << i << '\n';
        if(input[i-1] != i) check=1;
    }
    
    if(check==0) {
        cout << "ascending";
        exit(0);
    }
    
    for(int i =8;i>=1;i--){
        if(input[8-i] != i) check=2;
    }
    
    if(check ==1) cout << "descending";
    else cout << "mixed";
    
    return 0;
}