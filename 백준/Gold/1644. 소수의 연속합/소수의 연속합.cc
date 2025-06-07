#include <iostream>
#include <vector>

using namespace std;

int n;
bool sosu[4000001] = {0,};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    for(int i =2;i<=n;i++){
        if(!sosu[i]){
            // cout << i << '\n';
            for(long long j = (long long)i*i;j<=n;j+=i){
                // cout << j << " ";
                sosu[j] = true;
            }
            // cout << '\n';
        }
    }
    
    vector<long long> sum_sosu;
    long long temp =2;
    sum_sosu.push_back(0);
    sum_sosu.push_back(temp);
    for(int i =3;i<=n;i++){
        if(!sosu[i]){
            temp += i;
            sum_sosu.push_back(temp);
        }
    }
    
    int point_1 = 1;
    int point_2 = 0;
    long long result=0;
    while(point_2 < point_1 && point_1 < sum_sosu.size()){
        long long value = sum_sosu[point_1] - sum_sosu[point_2];
        if(value < n){
            point_1++;
        }
        else if(value > n){
            point_2++;
        }
        else{
            result++;
            point_1++;
            point_2++;
        }
    }
    
    cout << result;
    
    return 0;
}