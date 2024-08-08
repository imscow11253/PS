#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <queue>

using namespace std;

int n,m;
vector<int> vec;
queue<int> qu;
queue<int> qu2;
int walk=0;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    
    int temp;
    while(n--){
        cin >>temp;
        vec.push_back(temp);
    }
    
    vec.push_back(0);
    sort(vec.begin(), vec.end());
    for(int a : vec){
        if(a ==0) break;
        qu.push(a);   
    }
    for(int i = vec.size()-1; i>=0;i--){
        if(vec[i]==0)break;
        qu2.push(vec[i]);
    }
    
    int max = (abs(vec[0]) > abs(vec[vec.size()-1])) ? abs(vec[0]) : abs(vec[vec.size()-1]);
    
    while(qu.front() != 0){
        walk += abs(qu.front());
        // cout << walk << '\n';
        qu.pop();
        for(int i=1;i<m;i++){
            if(qu.front() != 0) qu.pop();
        }
    }
    
    while(qu2.front() != 0){
        walk += qu2.front();
        // cout << walk << '\n';
        qu2.pop();
        for(int i =1;i<m;i++){
            if(qu2.front() != 0) qu2.pop();
        }
    }
    
    cout << walk * 2 - max;
    
    return 0;
}