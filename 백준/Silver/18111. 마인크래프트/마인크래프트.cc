#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int n,m,b;
int ground[500][500] = {0,};
int max_value=0, min_value=1000;
int sum=0;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m >> b;
    for(int i =0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> ground[i][j];
            max_value = max(max_value, ground[i][j]);
            min_value = min(min_value, ground[i][j]);
            sum += ground[i][j];
        }
    }
    
    int result_time = INT_MAX;
    int result_height;
    for(int i = max_value; i>= min_value;i--){
        if(i*n*m > sum + b) continue;
        
        int temp_time = 0;
        
        for(int j=0;j<n;j++){
            for(int k =0;k<m;k++){
                if(ground[j][k] == i) continue;
                if(ground[j][k] > i) temp_time += (ground[j][k]-i) * 2;
                else temp_time += (i - ground[j][k]);
            }
        }
        
        // cout << i << " " << temp_time << '\n';
        
        if(result_time > temp_time){
            result_time = temp_time;   
            result_height = i;
        }
    }
    
    cout << result_time << " " << result_height;
    
    return 0;
}