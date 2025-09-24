#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int w,h,n,m;
    cin >> w >> h >> n >> m;
    
    int cnt =1;
    
    for(int i =1;i<w;i++){
        i += n;
        if(i < w) cnt++;
    }
    int index = cnt;
    for(int i=1;i<h;i++){
        i += m;
        if(i < h) cnt += index;
    }
    
    cout << cnt;
    
    return 0;
}