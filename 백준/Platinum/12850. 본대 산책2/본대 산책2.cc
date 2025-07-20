#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

long long d;
long long mod = 1000000007;

vector<vector<long long>> init = {
    {0, 1, 1, 0, 0, 0, 0, 0},
	{1, 0, 1, 1, 0, 0, 0, 0},
	{1, 1, 0, 1, 1, 0, 0, 0},
	{0, 1, 1, 0, 1, 1, 0, 0},
	{0, 0, 1, 1, 0, 1, 0, 1},
	{0, 0, 0, 1, 1, 0, 1, 0},
	{0, 0, 0, 0, 0, 1, 0, 1},
	{0, 0, 0, 0, 1, 0, 1, 0}
};

vector<vector<long long>> multiply_matrix(const vector<vector<long long>> &a, const vector<vector<long long>> &b ){
    vector<vector<long long>> result(8, vector<long long>(8,0));
    for(int i =0;i<8;i++){
        for(int j =0;j<8;j++){
            for(int k =0;k<8;k++){
                result[i][j] += a[i][k] * b[k][j];
                result[i][j] %= mod;
            }
        }
    }
    
    return result;
}

vector<vector<long long>> matrix_pow(vector<vector<long long>> base, long long cnt){
    vector<vector<long long>> result(8, vector<long long>(8,0));
    for(int i =0;i<8;i++) result[i][i] = 1;
    
    while(cnt){
        if(cnt & 1) result = multiply_matrix(result, base);
        base = multiply_matrix(base, base);
        cnt >>= 1;
    }
    
    return result;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> d;
    
    auto ans = matrix_pow(init, d);
    cout << ans[0][0];
       
    return 0;
}