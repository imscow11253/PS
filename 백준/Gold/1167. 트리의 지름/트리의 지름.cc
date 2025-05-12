#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node{
    int num;
    vector<pair<int,int>> childs;
};

Node arr[100001];
bool visit[100001] = {0,};
int n;
int result =0;

int find_diameter(int root){
    visit[root] = true;
    if(arr[root].childs.size() ==0) return 0;
    
    vector<int> distance;
    for(auto a : arr[root].childs){
        if(visit[a.first]) continue;
        distance.push_back(find_diameter(a.first) + a.second);
    }
    
    // cout << root << " : \n";
    // for(int a : distance) cout << a << " "; cout << '\n';
    
    sort(distance.begin(), distance.end(), greater<>());
    
    if(distance.size() >= 2) result = max(result, distance[0] + distance[1]);
    else if(distance.size() == 1) result = max(result , distance[0]);
    
    if(distance.size() ==0) return 0;
    else return distance[0];
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    int root, node, value;
    for(int i =1;i<=n;i++){
        cin >> root;
        cin >> node;
        while(node != -1){
            cin >> value;
            arr[root].childs.push_back({node, value});
            cin >> node;
        }
    }
    
    find_diameter(1);
    
    cout << result;
    
    return 0;
}