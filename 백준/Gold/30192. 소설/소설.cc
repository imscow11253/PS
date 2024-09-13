#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n,k;
string str;
vector<pair<int,int>> vec;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >>  n >> k;
    cin >> str;
    
    for (int i = 1; i < n; i++) {
        if (str[i] == str[i - 1]) {
            int sta = i - 1;
            while (i < n && str[i] == str[i - 1]) {
                i++;
            }
            int end = i - 1;
            if (end - sta + 1 >= k) {
                vec.push_back({sta, end});
            }
        }
    }


    int result =1;
    for(int i=1;i<=n;i++){
        int check =0;
        for(auto p : vec){
            int sta = p.first;
            int end = p.second;
            // cout << sta << " " << end << '\n';
            
            if(sta == 0 && (end - sta+1) >= k && i >= k) {check=1; break;}
            if(sta%i != 0 && i-(sta%i) >= k) {check=1; break;}
            else if(sta%i != 0 && (end - sta+1)-(i-(sta%i)) >= k && i >= k) {check=1; break;}
            else if(sta%i == 0 && (end - sta+1) >= k && i >= k) {check=1; break;}
        }
        if(check) continue;
        else  result = i;
    }
    
    cout << result;
    
    return 0;
}