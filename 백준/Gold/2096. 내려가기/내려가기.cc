#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int n;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    int a,b,c;
    int max_pre_dp_a=0, max_pre_dp_b=0, max_pre_dp_c=0;
    int max_dp_a=0, max_dp_b=0, max_dp_c=0;
    int min_pre_dp_a=0, min_pre_dp_b=0, min_pre_dp_c=0;
    int min_dp_a=INT_MAX, min_dp_b=INT_MAX, min_dp_c=INT_MAX;
    for(int i =0;i<n;i++){
        cin >> a >> b >> c;
        max_dp_a = max(max_pre_dp_a + a, max_pre_dp_b + a);
        max_dp_b = max(max_pre_dp_a + b, max_pre_dp_b + b);
        max_dp_b = max(max_dp_b, max_pre_dp_c + b);
        max_dp_c = max(max_pre_dp_b + c, max_pre_dp_c + c);
        
        max_pre_dp_a = max_dp_a;
        max_pre_dp_b = max_dp_b;
        max_pre_dp_c = max_dp_c;
        
        min_dp_a = min(min_pre_dp_a + a, min_pre_dp_b + a);
        min_dp_b = min(min_pre_dp_a + b, min_pre_dp_b + b);
        min_dp_b = min(min_dp_b, min_pre_dp_c + b);
        min_dp_c = min(min_pre_dp_b + c, min_pre_dp_c + c);
        
        min_pre_dp_a = min_dp_a;
        min_pre_dp_b = min_dp_b;
        min_pre_dp_c = min_dp_c;
    }
    
    cout << max(max_dp_a, max(max_dp_b, max_dp_c)) << " " << min(min_dp_a, min(min_dp_b, min_dp_c));
    
    return 0;
}