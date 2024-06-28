#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int n;
int arr[27][27]= {0,};
int visit[27][27]= {0,};
vector<int> vec;

int travel(int i, int j){
    visit[i][j] =1;
    int cnt =1;
    
    // if(!visit[i-1][j-1] && arr[i-1][j-1]){
    //     cnt += travel(i-1,j-1);
    // }
    if(!visit[i-1][j] && arr[i-1][j]){
        cnt += travel(i-1,j);
    }
    // if(!visit[i-1][j+1] && arr[i-1][j+1]){
    //     cnt += travel(i-1,j+1);
    // }
    if(!visit[i][j-1] && arr[i][j-1]){
        cnt += travel(i,j-1);
    }
    if(!visit[i][j+1] && arr[i][j+1]){
        cnt += travel(i,j+1);
    }
    // if(!visit[i+1][j-1] && arr[i+1][j-1]){
    //     cnt += travel(i+1,j-1);
    // }
    if(!visit[i+1][j] && arr[i+1][j]){
        cnt += travel(i+1,j);
    }
    // if(!visit[i+1][j+1] && arr[i+1][j+1]){
    //     cnt += travel(i+1,j+1);
    // }
    return cnt;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    string temp;
    int temp2;
    int col=0;
    for(int i=1;i<=n;i++){
        cin >> temp;
        col=0;
        for(char a : temp){
            col++;
            if(a == '0') temp2 = 0;
            else temp2 =1;
            arr[i][col] = temp2;
        }
    }
    int cnt;
    for(int i=1;i<=25;i++){
        for(int j=1;j<=25;j++){
            if(!visit[i][j] && arr[i][j]){
                cnt = travel(i,j);
                vec.push_back(cnt);
            }
        }
    }
    
    cout << vec.size() <<'\n';
    sort(vec.begin(), vec.end());
    for(int a : vec){
        cout << a << '\n';
    }
    
    return 0;
}