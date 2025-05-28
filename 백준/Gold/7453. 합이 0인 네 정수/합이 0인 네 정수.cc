#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int n;
int A[4000];
int B[4000];
int C[4000];
int D[4000];

int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    
    cin >> n;
    int a,b;
    for(int i =0;i<n;i++){
        cin >> A[i] >> B[i] >> C[i] >> D[i];
    }
    
    vector<int> ab, cd;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            ab.push_back(A[i] + B[j]);
            cd.push_back(C[i] + D[j]);
        }
    sort(ab.begin(), ab.end());
    sort(cd.begin(), cd.end());
    
    int p1 = 0, p2 = cd.size()-1;
    long long result = 0;
    while(p1 < ab.size() && p2 >= 0){
        int sum = ab[p1] + cd[p2];
        if(sum == 0){
            int a_cnt = 1, b_cnt = 1;
            while(p1+1 < ab.size() && ab[p1] == ab[p1+1]){ a_cnt++; p1++; }
            while(p2-1 >= 0 && cd[p2] == cd[p2-1]){ b_cnt++; p2--; }
            result += (long long)a_cnt * b_cnt;
            p1++; p2--;
        }
        else if(sum < 0) p1++;
        else p2--;
    }
    
    cout << result;
    
    return 0;
}