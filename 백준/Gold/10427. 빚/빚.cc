#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int t;
vector<int> vec;
vector<int> sum;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> t;
    
    int n; int temp;
    while(t--){
        cin >>n;
        vec.clear();
        for(int i =0;i<n;i++){
            cin >> temp;
            vec.push_back(temp);
        }
        
        sort(vec.begin(), vec.end(), greater<>());
        sum.clear();
        sum.push_back(vec[0]);
        for(int i =1;i<n;i++){
            sum.push_back(vec[i] + sum[i-1]);
        }
        
        long long cnt=0;
        for(int i=2;i<=n;i++){
            long long min = LONG_LONG_MAX;
            for(int j=0;j<=n-i;j++){
                long long result=0;
                result = vec[j]*i;
                
                // cout << result << " ";
                
                result -= sum[j+i-1];
                // cout << result << " ";
                if(j!=0){
                    result += sum[j-1];
                    // cout << result << " ";
                }
                
                if(result < min) min = result;
                // cout << '\n';
            }
            cnt += min;
        }
        
        printf("%lld\n",cnt);
    }
    
    return 0;
}