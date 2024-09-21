#include <iostream>
#include <algorithm>
#include <stdlib.h>

using namespace std;

int arr[10];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    for(int i =0;i<n;i++){
        cin >> arr[i];
    }
    
    int result=0;
    for(int i=1;i<n-2;i++){
        for(int j = i+1;j<n-1;j++){
            for(int k=j+1;k<n;k++){
                int a =1;
                for(int t = 0;t<i;t++) a *= arr[t];
                int b =1;
                for(int t = i;t<j;t++) b *= arr[t];
                int c =1;
                for(int t = j;t<k;t++) c *= arr[t];
                int d =1;
                for(int t = k;t<n;t++) d *= arr[t];
                result = max(result, a+b+c+d);
            }
        }
    }
    cout << result;
    return 0;
}