#include <iostream>
using namespace std;

int dist[21][21];
bool need[21][21];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> dist[i][j];
            need[i][j] = true;
        }
    }

    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==j || i==k || j==k) continue;

                if(dist[i][j] > dist[i][k] + dist[k][j]){
                    cout << -1;
                    return 0;
                }

                if(dist[i][j] == dist[i][k] + dist[k][j]){
                    need[i][j] = false;
                }
            }
        }
    }

    int result = 0;

    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(need[i][j]) result += dist[i][j];
        }
    }

    cout << result;
}