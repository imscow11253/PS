#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> vec;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    int temp;
    for(int i =0;i<n;i++){
        cin >> temp;
        vec.push_back(temp);
    }
    
    int max_cnt =0;
    int num=1;
    int prev_value = vec[0];
    int cur_cnt=1;
    for(int i =1;i<n;i++){
        int a = vec[i];
        if(a < prev_value) {
            max_cnt = max(max_cnt, cur_cnt);
            cur_cnt=1;
            num++;
        }
        else{
            cur_cnt++;
        }
        prev_value = a;
    }
    max_cnt = max(max_cnt, cur_cnt);
    
    cout << num << " " << max_cnt;
    
    return 0;
}