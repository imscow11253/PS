#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N,C;
    cin >> N >> C;
    
    int arr[N];
    for(int i=0;i<N;i++) cin >> arr[i];
    sort(arr, arr+N);
    
    int low = 1, high = arr[N-1]-arr[0], mid, re=0;
    int cnt, temp;
    while(low<=high){
        cnt=1; temp = arr[0];
        mid = (low+high)/2;
        for(int i=1;i<N;i++){
            if(arr[i]-temp >= mid){
                temp = arr[i];
                cnt++;
            }
        }
        if(cnt < C){
            high = mid-1;
        }else{
            low = mid+1;
            re = mid;
        }
    }
    
    cout << re;
    
    return 0;
}