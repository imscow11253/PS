#include <iostream>
#include <string>
#include <algorithm>
#include <bitset>
#include <vector>

using namespace std;

int n;
vector<bitset<50>> friends;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    
    string str;
    for(int i =0;i<n;i++){
        cin >> str;
        string temp="";
        for(int j=0;j<n;j++){
            if(str[j] == 'Y'){
                temp += "1";
            }
            else temp += "0";
        }
        bitset<50> temp_bit(temp);
        friends.push_back(temp_bit);
    }
    
    int max_num=0;
    for(int i =0;i<n;i++){
        bitset<50> num = friends[i];
        for(int j =0;j<n;j++){
            if(friends[i][j]){
                num |= friends[n-1-j];
            }
        }
        int one_num = num.count()-1;
        // cout << num << '\n';
        // cout << one_num << '\n';
        max_num = max(max_num, one_num);
    }
    
    cout << max_num;
    
    return 0;
}