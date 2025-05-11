#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> vec;

void travel(int sta, int en){
    if(sta >= en) return;
    int root = vec[sta];
    int right_node = sta+1;
    for(int i = sta;i<en;i++){
        if(vec[i] > root){
            right_node = i;
            break;
        }
    }
    
    // cout << sta +1 << " " << right_node<<'\n';
    // cout << right_node << " " << en << '\n';
    travel(sta+1, right_node);
    travel(right_node, en);
    cout << root<< '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int temp;
    while(cin >> temp){
        vec.push_back(temp);
    }
    
    travel(0, vec.size());
    
    return 0;
}