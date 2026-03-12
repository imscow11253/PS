#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int n,m;
char arr[50][50];
bool visit[50][50][64];

int dr[4]={-1,1,0,0};
int dc[4]={0,0,-1,1};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m;

    int sr,sc;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
            if(arr[i][j]=='0'){
                sr=i;
                sc=j;
            }
        }
    }

    queue<tuple<int,int,int,int>> q;
    q.push({sr,sc,0,0});
    visit[sr][sc][0]=true;

    while(!q.empty()){
        auto [r,c,dist,key]=q.front();
        q.pop();

        if(arr[r][c]=='1'){
            cout<<dist;
            return 0;
        }

        for(int d=0;d<4;d++){
            int nr=r+dr[d];
            int nc=c+dc[d];
            int nk=key;

            if(nr<0||nc<0||nr>=n||nc>=m) continue;
            if(arr[nr][nc]=='#') continue;

            char next=arr[nr][nc];

            if(next>='a'&&next<='f')
                nk |= (1<<(next-'a'));

            if(next>='A'&&next<='F'){
                if(!(key & (1<<(next-'A'))))
                    continue;
            }

            if(!visit[nr][nc][nk]){
                visit[nr][nc][nk]=true;
                q.push({nr,nc,dist+1,nk});
            }
        }
    }

    cout<<-1;
}