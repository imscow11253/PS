#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> vec;
vector<int> defile;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    
    int temp;
    while(n--){
        cin >> temp;
        vec.push_back(temp);
    }
    
    sort(vec.begin(), vec.end());
    
    int index=1;
    long long result =0;
    for(int i=0;i<vec.size();i){
        if(vec[i] <= index){
            while(vec[i] <=index && i < vec.size()){
                defile.push_back(index);
                i++;
            }
            index++;
        }
        else{
            result += vec[i] - index;
            defile.push_back(index);
            index++; i++;
        }
        
        if(i == vec.size()) break;
    }
    
    cout << result;
    
    return 0;
}