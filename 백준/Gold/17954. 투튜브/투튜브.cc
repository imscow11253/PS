#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    if(n==1){
        cout << 2 << '\n';
        cout << 1 << '\n';
        cout << 2;
        exit(0);
    }
    
    long long sum=0;
    for(int i =1;i<=2*n;i++){
        sum += i;
    }
    
    vector<int> vec;
    int index = 2*n - 3;
    for(int i=0;i<2*n;i++){
        if(i == n-1){
            vec.push_back(2*n - 2);
        }
        else if(i == n) vec.push_back(2*n-1);
        else if(i == 2*n-1) vec.push_back(2*n);
        else vec.push_back(index--);
    }
    
    // for(int a : vec) cout << a << " ";
    // cout << '\n';
    
    long long result =0;
    for(int i=1;i<=2*n;i++){
        sum -= vec[i-1];
        result += i * sum;
    }
    
    cout << result << '\n';
    
    for(int i =0;i<2*n;i++){
        // if(i == n-1) cout << 2*n  << " " << '\n';
        // else if( i == 2*n -1) cout << 2*n-1 << " ";
        // else if(i > n-1) cout << vec[i-1] << " ";
        // else cout << vec[i] << " ";
        cout << vec[i] << " ";
        if(i == n-1) cout << '\n';
    }
    
    // cout << result;
    
    return 0;
}