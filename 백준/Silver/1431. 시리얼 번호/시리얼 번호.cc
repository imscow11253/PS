#include <iostream>
#include <queue>

using namespace std;

struct Compare{
  bool operator()(string a, string b){
    if(a.length() != b.length()) return a.length() > b.length();
    int sum_a =0;
    for(char c : a) if(c >= '0' && c <= '9') sum_a += (c - '0');
    int sum_b =0;
    for(char c : b) if(c >= '0' && c <= '9') sum_b += (c - '0');
    if(sum_a != sum_b) return sum_a > sum_b;
    return a > b;
  }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n;
  cin >> n;
  
  priority_queue<string, vector<string>, Compare> pq;
  while(n--){
    string str;
    cin >>str;
    pq.push(str);
  }
  
  while(!pq.empty()){
    cout << pq.top() << '\n';
    pq.pop();
  }
  
  return 0;
}