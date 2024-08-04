#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>

using namespace std;

int t,n;
vector<int> vec;
int arr[10000] ={};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> t;
    
    while(t--){
        cin >> n;
        int temp;
        int size = n;
        vec.clear();
        while(n--){
            cin >> temp;
            vec.push_back(temp);
        }
        
        sort(vec.begin(), vec.end());
        
        int start =0;
        int end = size-1;
        for(int i =0;i<size;i++){
            if(i%2 ==0){
                arr[start++] = vec[i];
            }
            else{
                arr[end--] = vec[i];
            }
            // for(int i=0;i<size;i++){
            //     cout << arr[i] << " ";
            // }cout << '\n';
        }

        int max = abs(arr[0]- arr[size-1]);
        for(int i=1;i<size;i++){
            if(max < abs(arr[i] - arr[i-1])) max =abs(arr[i] - arr[i-1]);
        }
        
        cout << max << '\n';
    }
    
    return 0;
}
