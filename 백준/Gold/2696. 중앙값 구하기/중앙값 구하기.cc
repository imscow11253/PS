#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--){
        int m;
        cin >> m;
        
        multiset<int> mst;
        vector<int> result;
        for(int i =1;i<=m;i++){
            int temp;
            cin >> temp;
            mst.insert(temp);
            // if(t == 1) {for(auto &a : mst) cout << a << " " ; cout << '\n';}
            if(i%2 == 1){
                auto it = mst.begin();
                for(int i =0;i<mst.size()/2;i++) it++;
                result.push_back(*it);
            }
        }
        cout << result.size() << '\n';
        int index =0;
        for(int &a : result) {
            cout<< a << " " ;
            index++;
            if(index % 10 ==0) cout<< '\n';
        }
        cout << '\n';
    }
    
    return 0;
}