#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <set>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,m;
    cin >> n >> m;
    
    set<int> st;
    
    int know_num;
    cin >> know_num;
    int temp;
    while(know_num--){
        cin >> temp;
        st.insert(temp);
    }
    
    int check=0;
    vector<vector<int>> party;
    int m2 = m;
    while(m--){
        vector<int> vec;
        cin >> temp;
        int temp2;
        while(temp--){
            cin >> temp2;
            if(st.find(temp2) != st.end()){
                check =1;
            }
            vec.push_back(temp2);
        }
        
        party.push_back(vec);
        
        if(check){
            for(int a : vec){
                st.insert(a);
            }
        }
        
        check=0;
    }
    
    while(m2--){
        for(auto a : party){
            for(auto b : a){
                if(st.find(b) != st.end()){
                    check=1;
                    break;
                }
            }
            if(check){
                for(auto b : a){
                    st.insert(b);
                }
            }
            check =0;
        }
    }
    
    int cnt=0;
    for(auto a : party){
        for(auto b : a){
            if(st.find(b) != st.end()){
                check=1;
            }
        }
        if(!check){
            cnt++;
        }
        check =0;
    }
    
    cout << cnt;

    return 0;
}
