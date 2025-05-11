#include <iostream>
#include <vector>

using namespace std;

struct Node{
    char ch;
    int left = -1;
    int right= -1;
};

int n;
Node arr[26];

void front_travel(int index){
    cout << arr[index].ch;
    if(arr[index].left != -1) front_travel(arr[index].left);
    if(arr[index].right != -1) front_travel(arr[index].right);
}

void middle_travel(int index){
    if(arr[index].left != -1) middle_travel(arr[index].left);
    cout << arr[index].ch;
    if(arr[index].right != -1) middle_travel(arr[index].right);
}

void back_travel(int index){
    if(arr[index].left != -1) back_travel(arr[index].left);
    if(arr[index].right != -1) back_travel(arr[index].right);
    cout << arr[index].ch;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    for(int i=0;i<26;i++){
        Node node;
        node.ch = 'A'+i;
        arr[i] = node;
    }
    
    char root, left, right;
    for(int i =0;i<n;i++){
        cin >> root >> left >> right;
        if(left != '.'){
            arr[root - 'A'].left = (left -'A');
        }
        if(right != '.'){
            arr[root - 'A'].right = (right -'A');
        }
    }
    
    front_travel(0);
    cout << '\n';
    middle_travel(0);
    cout << '\n';
    back_travel(0);
    cout << '\n';
    
    return 0;
}