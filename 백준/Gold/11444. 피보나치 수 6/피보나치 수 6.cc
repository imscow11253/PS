#include <iostream>
#include <vector>

using namespace std;

vector<vector<long long int>> vec = {{1,1},{1,0}};

void matrix(long long int N){
    if(N==1) return;
    else{
        matrix(N/2);
        vector<vector<long long int>> temp_vec =vec;
        for(int i =0;i<2;i++){
            for(int j=0;j<2;j++){
                long long int temp=0;
                for(int k=0;k<2;k++)  temp += (temp_vec[i][k] * temp_vec[k][j])%1000000007;
                vec[i][j] = temp;
            }
        }
        if(N%2==1){
            temp_vec = vec;
            vec[0][0] = (temp_vec[0][0] + temp_vec[0][1])%1000000007;
            vec[0][1] = temp_vec[0][0];
            vec[1][0] = (temp_vec[1][0] + temp_vec[1][1])%1000000007;
            vec[1][1] = temp_vec[1][0];
        }
        // cout << N << "  =========================\n";
        // for(int i=0;i<2;i++){
        //     for(int j=0;j<2;j++) cout << vec[i][j] << " ";
        //     cout << '\n';
        // }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long int N;
    cin >> N;
    
    matrix(N);
    cout << vec[0][1]%1000000007;
    
    return 0;
}