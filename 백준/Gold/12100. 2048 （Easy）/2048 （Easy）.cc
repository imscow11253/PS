#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int n;
int max_value = 0;

void travel(int direction, int cnt, vector<vector<int>> arr){
    if(cnt == 5) return ;
    
    if(direction == 1){
        for(int i =0;i<n;i++){
            int index = n-1;
            int check = false;
            for(int j = n-1; j>=0; j--){
                if(arr[i][j] != 0){
                    if(index +1 < n && arr[i][index+1] == arr[i][j] && !check){
                        arr[i][index+1] = arr[i][j] * 2;
                        check = true;
                        arr[i][j] =0;
                    } 
                    else{
                        arr[i][index] = arr[i][j];
                        if(j != index) arr[i][j] =0;
                        index--;
                        check = false;
                    }
                }
            }
        }
    }
    else if(direction == 2){
        for(int i =0;i<n;i++){
            int index = 0;
            int check = false;
            for(int j = 0; j<n; j++){
                if(arr[i][j] != 0){
                    if(index -1 >= 0 && arr[i][index-1] == arr[i][j] && !check){
                        arr[i][index-1] = arr[i][j] * 2;
                        check = true;
                        arr[i][j] =0;
                    } 
                    else{
                        arr[i][index] = arr[i][j];
                        if(j != index) arr[i][j] =0;
                        index++;
                        check = false;
                    }
                }
            }
        }
    }
    else if(direction == 3){
        for(int j = 0; j<n; j++){
            int index = n-1;
            int check = false;
            for(int i =n-1;i>=0;i--){
                if(arr[i][j] != 0){
                    if(index +1 < n && arr[index+1][j] == arr[i][j] && !check){
                        arr[index+1][j] = arr[i][j] * 2;
                        check = true;
                        arr[i][j] =0;
                    } 
                    else{
                        arr[index][j] = arr[i][j];
                        if(i != index) arr[i][j] =0;
                        index--;
                        check = false;
                    }
                }
            }
        }
    }
    else{
        for(int j = 0; j<n; j++){
            int index = 0;
            int check = false;  
            for(int i =0;i<n;i++){
                if(arr[i][j] != 0){
                    if(index -1 >= 0 && arr[index-1][j] == arr[i][j] && !check){
                        arr[index-1][j] = arr[i][j] * 2;
                        check = true;
                        arr[i][j] =0;
                    } 
                    else{
                        arr[index][j] = arr[i][j];
                        if(i != index) arr[i][j] =0;
                        index++;
                        check = false;
                    }
                }
            }
        }
    }
    
    // if(cnt == 0){
    //     cout << direction << '\n';
    //     for(int i =0;i<n;i++){
    //         for(int j =0;j<n;j++){
    //             cout << arr[i][j] << " " ;
    //         }cout << '\n';
    //     }   
    // }
    
    for(int i =0;i<n;i++){
        for(int j =0;j<n;j++){
            max_value = max(max_value, arr[i][j]);
        }
    }
    
    for(int i =1;i<5;i++){
        travel(i, cnt+1, arr);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
     vector<vector<int>> arr(n, vector<int>(n));
     
    for(int i =0;i<n;i++){
        for(int j =0;j<n;j++){
            cin >> arr[i][j];
        }
    }
    
    for(int i =1;i<5;i++){
        travel(i, 0, arr);
    }
    
    cout << max_value;
    
    return 0;
}