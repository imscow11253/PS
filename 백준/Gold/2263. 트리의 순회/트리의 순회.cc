#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>

using namespace std;

int n;
vector<int> inOrder;
vector<int> postOrder;
vector<int> preOrder;
unordered_map<int,int> inOrderIndex;

void calPreOrder(int inSta, int inEn, int postSta, int postEn){
    if (inSta > inEn || postSta > postEn) return;
    // cout << inSta << " " << inEn << " " << postSta << " " << postEn << '\n';
    if(inSta == inEn) {
        preOrder.push_back(inOrder[inSta]);
        return ;
    }
    
    int root = postOrder[postEn];
    preOrder.push_back(root);
    
    int index = inOrderIndex[root];
    calPreOrder(inSta, index-1, postSta, postSta + (index - inSta - 1));
    calPreOrder(index+1, inEn, postSta + (index - inSta), postEn-1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    int temp;
    for(int i =0;i<n;i++){
        cin >> temp;
        inOrder.push_back(temp);
        inOrderIndex[temp] = i;
    }
    for(int i =0;i<n;i++){
        cin >> temp;
        postOrder.push_back(temp);
    }
    
    calPreOrder(0, n-1, 0, n-1);
    for(int a : preOrder) cout << a << " ";
    
    return 0;
}