#include <iostream>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

int n,k;
int arr[100001] = {0,};
int min_distance = INT_MAX;
int cnt =0;

void bfs(){
    queue<pair<int,int>> qu;
    qu.push({n,0});
    
    while(!qu.empty()){
        auto a = qu.front();
        qu.pop();
        
        int position = a.first;
        int distance = a.second;

        // cout << "=========== " << position << " " << distance <<" ============"<< '\n';
        
        if(position == k){
            min_distance = distance;
        }
        
        if(distance +1 > min_distance) continue;
        if(position -1 >=0 && position-1 != n && (distance <= arr[position-1] || arr[position-1] == 0)){
            qu.push({position-1, distance+1});
            arr[position-1] = distance;
            if(position-1 == k) cnt++;
            // cout << position -1 << " " << distance+1 << '\n';
        }
        if(position +1 < 100001 && position+1 != n && (distance <= arr[position+1] || arr[position+1] == 0)){
            qu.push({position+1, distance+1});
            arr[position+1] = distance;
            if(position+1 == k) cnt++;
            // cout << position +1 << " " << distance+1 << '\n';
        }
        if(position *2 < 100001 && position*2 != n && (distance <= arr[position*2] || arr[position*2] == 0)){
            qu.push({position*2, distance+1});
            arr[position*2] = distance;
            if(position*2 == k) cnt++;
            // cout << position *2 << " " << distance+1 << '\n';
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> k;
    bfs();
    
    if(min_distance ==0 ) cout << min_distance << '\n' << 1;
    else cout << min_distance << '\n' << cnt;
    
    return 0;
}
