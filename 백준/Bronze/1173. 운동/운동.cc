#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,m,M,t,r;
    cin >> n >> m >> M >> t >> r;
    if(m + t > M) {cout << -1; return 0; }
    int time_cnt=0;
    int work_cnt=0;
    int bit = m;
    while(work_cnt < n){
        if(bit + t <= M) {work_cnt++; bit += t;}
        else{
            bit -= r;
            if(bit < m) bit =m;
        }
        time_cnt++;
    }
    cout << time_cnt;
    
    return 0;
}