#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node{
    int num;
    vector<pair<int,int>> childs;
};

Node arr[10001];
int n;
int result =0;

int find_diameter(int root){
    if(arr[root].childs.size() ==0) return 0;
    
    vector<int> distance;
    for(auto a : arr[root].childs){
        distance.push_back(find_diameter(a.first) + a.second);
    }
    
    // cout << root << " : \n";
    // for(int a : distance) cout << a << " "; cout << '\n';
    
    sort(distance.begin(), distance.end(), greater<>());
    
    if(distance.size() >= 2) result = max(result, distance[0] + distance[1]);
    else if(distance.size() == 1) result = max(result , distance[0]);
    
    return distance[0];
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    int parent, child, value;
    while(cin >> parent){
        cin >> child >> value;
        arr[parent].childs.push_back({child, value});
    }
    
    find_diameter(1);
    
    cout << result;
    
    return 0;
}