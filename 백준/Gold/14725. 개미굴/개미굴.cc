#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

struct Node{
  map<string, Node*> child;
  bool isEnd;
};

int n;
Node* root;

void save(Node* node, vector<string> &vec, int index){
  if(index >= vec.size()) return ;
  
  auto &mp = node->child;
  string str = vec[index];
  if(mp.find(str) == mp.end()){
    mp.insert({str, new Node()});
    if(vec.size() -1 == index) mp[str]->isEnd = true;
  }
  save(mp[str], vec, index+1);
}

void print(Node* node, int index){
  for(auto &p : node->child){
    for(int i =0;i<index;i++) cout << "--";
    cout << p.first << '\n';
    print(p.second, index+1);
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  cin >> n;
  root = new Node();
  root->isEnd = false;
  for(int i =0;i<n;i++){
    int m;
    cin >> m;
    
    vector<string> vec(m);
    for(int j =0;j<m;j++){
      cin >> vec[j];
    }
    
    save(root, vec, 0);
  }
  
  for(auto p : root->child){
    cout << p.first << '\n';
    print(p.second, 1);
  }
  
  return 0;
}