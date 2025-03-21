#include <string>
#include <vector>

using namespace std;

vector<vector<int>> vec;

int solution(int n, vector<vector<int>> q, vector<int> ans) {
    int answer = 0;
    
    //후보 키 i,j,k,a,b
    for(int i =1;i<=n-4;i++){
        for(int j = i+1;j<=n-3;j++){
            for(int k=j+1;k<=n-2;k++){
                for(int a = k+1; a <= n-1;a++){
                    for(int b=a+1;b<=n;b++){
                        vector<int> temp;
                        temp.push_back(i);
                        temp.push_back(j);
                        temp.push_back(k);
                        temp.push_back(a);
                        temp.push_back(b);
                        vec.push_back(temp);
                    }
                }
            }
        }
    }
    
    for(auto a : vec){
        int check = 1;
        for(int j =0;j<q.size();j++){
            int cnt=0;
            auto b = q[j];
            for(int aa : a){
                for(int bb :b){
                    if(aa == bb) {cnt++; break;}
                }
            }
            if(ans[j] != cnt){
                check=0;
                break;
            }
        }
        if(check) answer++;
    }
    
    return answer;
}