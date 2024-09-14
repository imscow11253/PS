#include <iostream>

using namespace std;

int n;
int arr[1000001];
long long result=0;

void merge(int sta, int end){
    if(sta >= end) return;
    else{
        int temp[end-sta+1];
        
        merge(sta, (sta+end)/2);
        merge((sta+end)/2 +1, end);
        
        int front_pointer = sta;
        int back_pointer = (sta+end)/2 +1;
        int temp_index=0;
        
        while(front_pointer <= (sta+end)/2 && back_pointer <= end){
            if(arr[front_pointer] <= arr[back_pointer]){
                temp[temp_index] = arr[front_pointer];
                temp_index++;
                front_pointer++;
            }
            else{
                temp[temp_index] = arr[back_pointer];
                result += (sta+end)/2 - front_pointer +1;
                // cout << result << " : " <<  arr[front_pointer] << " " << arr[back_pointer] << '\n';
                temp_index++;
                back_pointer++;
            }
        }
        while(front_pointer <= (sta+end)/2) temp[temp_index++] = arr[front_pointer++];
        while(back_pointer <= end) temp[temp_index++] = arr[back_pointer++];
        for(int i=sta; i<=end;i++){
            arr[i] = temp[i-sta];
        }
        // for(int i =1;i<=n;i++){
        //     cout << arr[i] << " ";
        // }cout << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> arr[i];
    }
    
    merge(1,n);
    
    cout <<result;
    
    return 0;
}