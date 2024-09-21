#include <iostream>

typedef long long ll;

using namespace std;

int n,t;
bool arr[2000001]={};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >>t;
    
    int temp;
    for(int i=0;i<n;i++){
        cin >> temp;
        for(int j=1;j<=t;j++){
            if(j%temp ==0) arr[j] = true;
        }
    }
    int result =0;
    for(bool a : arr) if(a) result++;
    cout << result;
    return 0;
}