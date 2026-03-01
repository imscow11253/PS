#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_set>

using namespace std;

int l,c;
unordered_set<char> st = {'a', 'e', 'i', 'u', 'o'};

void dfs(vector<char> &vec, int index, string str, int vowel, int consonant){
  if(str.length() == l){
    if(vowel > 0 && consonant > 1){
      cout << str << '\n';
      return ;
    }
  }
  
  for(int i =index;i<c;i++){
    if(st.find(vec[i]) != st.end()) vowel++;
    else consonant++;
    dfs(vec, i+1, str + vec[i], vowel, consonant);
    if(st.find(vec[i]) != st.end()) vowel--;
    else consonant--;
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  cin >> l >> c;
  vector<char> vec(c);
  for(int i =0;i<c;i++){
    cin >> vec[i];
  }
  
  sort(vec.begin(), vec.end());
  
  int vowel =0;
  int consonant =0;
  dfs(vec, 0, "", vowel, consonant);
  
  return 0;
}