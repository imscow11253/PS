#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n,m,l,k;
  cin >> n >> m >> l >> k;
  
  vector<pair<int,int>> stars(k);
  int a,b;
  for(int i =0;i<k;i++){
    cin >> a >> b;
    stars[i] = {a,b};
  }
  
  int result =0;
  for(int j =0;j<k;j++){
    for(int t=0;t<k;t++){
      int x = stars[j].first;
      int y = stars[t].second;
      
      int rectangle_1=0;
      int rectangle_2=0;
      int rectangle_3=0;
      int rectangle_4=0;
      for(int i =0;i<k;i++){
        int _x = stars[i].first;
        int _y = stars[i].second;
        
        if(_x >= x - l && _x <= x && _y >= y - l && _y <= y) rectangle_1++;
        if(_x >= x && _x <= x + l && _y >= y - l && _y <= y) rectangle_2++;
        if(_x >= x && _x <= x + l && _y >= y && _y <= y + l) rectangle_3++;
        if(_x >= x - l && _x <= x && _y >= y && _y <= y + l) rectangle_4++;
      }
      result = max(result, rectangle_1);
      result = max(result, rectangle_2);
      result = max(result, rectangle_3);
      result = max(result, rectangle_4);
    }
  }
    // for(auto p : stars){
    //   int x = p.first;
    //   int y = p.second;
      
    //   int rectangle_1=0;
    //   int rectangle_2=0;
    //   int rectangle_3=0;
    //   int rectangle_4=0;
    //   for(int i =0;i<k;i++){
    //     int _x = stars[i].first;
    //     int _y = stars[i].second;
        
    //     if(_x >= x - l && _x <= x && _y >= y - l && _y <= y) rectangle_1++;
    //     if(_x >= x && _x <= x + l && _y >= y - l && _y <= y) rectangle_2++;
    //     if(_x >= x && _x <= x + l && _y >= y && _y <= y + l) rectangle_3++;
    //     if(_x >= x - l && _x <= x && _y >= y && _y <= y + l) rectangle_4++;
    //   }
    //   result = max(result, rectangle_1);
    //   result = max(result, rectangle_2);
    //   result = max(result, rectangle_3);
    //   result = max(result, rectangle_4);
       
    //   // cout << x << " " << y << '\n';
    //   // cout << rectangle_1 << " " << rectangle_2 << " " << rectangle_3 << " " << rectangle_4 << '\n';
    // }
    
  cout << k - result;
  
  return 0;
}