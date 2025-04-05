#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    long long ans=n;
    int temp;
    vector<int> stu_num;
    while(n--){
        cin >> temp;
        stu_num.push_back(temp);
    }
    
    int b,c;
    cin >> b >>c;
    for(int a : stu_num){
        if((a-b) > 0){
            if((a-b)%c > 0){
                ans+= (a-b)/c+1;
            }
            else ans += (a-b)/c;
        }
    }
    
    cout << ans;
    
    return 0;
}