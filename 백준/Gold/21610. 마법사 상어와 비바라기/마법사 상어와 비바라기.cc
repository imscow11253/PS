#include <iostream>
#include <set>
#include <algorithm>
#include <vector>

using namespace std;

int n,m;
int arr[51][51] = {0,};
set<pair<int,int>> cloudy;
set<pair<int,int>> cloud;
set<pair<int,int>> moved_cloud;
pair<int,int> move_to[9] = {
    {0,0}, {0, -1}, {-1,-1}, {-1,0}, {-1,1}, {0,1}, {1,1}, {1,0}, {1,-1}
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> arr[i][j];
            if(arr[i][j] >= 2) cloudy.insert({i,j});
        }
    }
    
    cloud.insert({n,1});
    cloud.insert({n,2});
    cloud.insert({n-1,1});
    cloud.insert({n-1,2});
    
    int d,s;
    while(m--){
        cin >> d >> s;
        
        // for(int i =1;i<=n;i++){
        //     for(int j =1;j<=n;j++){
        //         cout << arr[i][j] << " ";
        //     }cout << '\n';
        // }
        
        // cout << d << " " << s << '\n';
        // cout << "cloud : ";
        // for(auto a : cloud) cout << "{" << a.first << ", " << a.second << "}, ";
        // cout << '\n';
        // cout << "cloudy : ";
        // for(auto a : cloudy) cout << "{" << a.first << ", " << a.second << "}, ";
        // cout << '\n';
        // cout << "moved_cloud : ";
        // for(auto a : moved_cloud) cout << "{" << a.first << ", " << a.second << "}, ";
        // cout << '\n';
        
        
        for(auto a : cloud){
            int row = a.first;
            int col = a.second;
            
            int moved_row = ((row-1+(move_to[d].first * s))%n+n)%n+1;
            int moved_col = ((col-1+(move_to[d].second * s))%n+n)%n+1;
            
            // cout << "insert : " << moved_row << " " << moved_col << '\n';
            moved_cloud.insert({moved_row,moved_col});
        }
        
        for(auto a : moved_cloud){
            int row = a.first;
            int col = a.second;
            
            arr[row][col]++;
        }
        
        for(auto a : moved_cloud){
            int row = a.first;
            int col = a.second;
            
            if(row-1 > 0 && col -1 > 0 && arr[row-1][col-1] > 0) arr[row][col]++;
            if(row-1 > 0 && col +1 <= n && arr[row-1][col+1] > 0) arr[row][col]++;
            if(row+1 <=n && col +1 <= n && arr[row+1][col+1] > 0) arr[row][col]++;
            if(row+1 <= n && col-1 >0 && arr[row+1][col-1] > 0) arr[row][col]++;
            
            if(arr[row][col] >= 2) cloudy.insert({row,col});
        }
        
        cloud.clear();
        
        set<pair<int,int>> candi_erase;
        for(auto a : cloudy){
            int row = a.first;
            int col = a.second;
            
            // cout << row << " " << col << '\n';
            
            if(moved_cloud.find({row,col}) != moved_cloud.end()) {
                // cout << "continue with " << row << " " << col << '\n';
                continue;
            }
            
            cloud.insert({row,col});
            arr[row][col] -= 2;
            
            if(arr[row][col] < 2) candi_erase.insert({row,col});
        }
        
        for(auto a : candi_erase){
            cloudy.erase({a.first, a.second});
        }
        
        moved_cloud.clear();
    }
    
    long long ans=0;
    for(int i =1;i<=n;i++){
        for(int j =1;j<=n;j++){
            ans += arr[i][j];
        }
    }
    cout << ans;
    
    return 0;
}