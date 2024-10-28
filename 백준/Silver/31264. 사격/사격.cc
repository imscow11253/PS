#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n,m,a;
vector<int> vec;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m >> a;
    int temp;
    for(int i =0;i<n;i++){
        cin >> temp;
        vec.push_back(temp);
    }
    sort(vec.begin(), vec.end());
        
    int ability=1;
    while(true){
        int temp_ability=ability;
        int temp_score=0;
        for(int i=0;i<m;i++){
            auto index = upper_bound(vec.begin(),vec.end(),temp_ability);
            if(index != vec.begin()){
                temp_ability += *(index-1);
                temp_score += *(index-1);
            }
            else{
                break;
            }
        }
        if(temp_score >= a){
            cout << ability;
            break;
        }
        else{
            ability++;
            continue;
        }
    }
    
    return 0;
}