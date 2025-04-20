#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int n;
vector<int> score;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    int temp;
    for(int i =0;i<n;i++){
        cin >> temp;
        score.push_back(temp);
    }
    
    if(n ==0 ) cout << 0;
    else {
        sort(score.begin(), score.end());
        double except_num = (double)n * 3 / 20;
        int real_except_num = floor(except_num + 0.5);
        double sum =0;
        for(int i = real_except_num; i < n-real_except_num; i++){
            sum += score[i];
        }
        
        double mean = sum / (n - (real_except_num*2));
        int real_mean = floor(mean+0.5);
        cout << real_mean;
    }
    
    return 0;
}