#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int n,s;
int stack_sum[100000];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> s;
    stack_sum[0] = 0;
    int temp;
    for(int i =1;i<=n;i++){
        cin >> temp;
        if(temp >= s){
            cout << 1;
            exit(0);
        }
        stack_sum[i] = stack_sum[i-1] + temp;
    }
    
    int point_1=0;
    int point_2=0;
    int result = INT_MAX;
    while(point_1 != n+1){
        if(stack_sum[point_1] - stack_sum[point_2] >= s){
            result = min(result, point_1-point_2);
            point_2++;
        }
        else point_1++;
    }
    
    if(result == INT_MAX) cout << 0;
    else cout <<result;
    
    return 0;
}