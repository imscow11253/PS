#include <iostream>
#include <algorithm>
 
using namespace std;

int n,k;
int arr[5000];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >>k;
    for(int i =0;i<n;i++){
        cin >> arr[i];
    }
    
    int temp;
    int result =0;
    int cnt;
    for(int i =0;i<n;i++){
        temp = k; cnt=1;
        for(int j=i+1;j<n;j++){
            if(arr[j] == arr[i]){
                cnt++;
                continue;
            }
            if(temp ==0) break;
            temp--;
        }
        result = max(cnt, result);
    }
    
    cout << result;
    
    return 0;
}