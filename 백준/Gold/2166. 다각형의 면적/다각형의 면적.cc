#include <iostream>
#include <stdlib.h>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;

int n;
vector<int> x_vec;
vector<int> y_vec;

int main(){
    ios_base::sync_with_stdio(false);(long long)
    cin.tie(NULL);
    
    cin >> n;
    int a,b;
    for(int i =0;i<n;i++){
        cin >> a >> b;
        x_vec.push_back(a);
        y_vec.push_back(b);
    }
    
    x_vec.push_back(x_vec[0]);
    y_vec.push_back(y_vec[0]);
    
    long double sum=0;
    for(int i =0;i<n;i++){
        sum += (long long)x_vec[i]*y_vec[i+1];
        sum -= (long long)x_vec[i+1]*y_vec[i];
    }
    
    cout << std::fixed << std::setprecision(1) << fabs(sum) /2;
    
    return 0;
}