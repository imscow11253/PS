#include <iostream>
#include <vector>

using namespace std;

int n;
vector<pair<int,int>> vec;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    
    int a,b;
    while(n--){
        cin >> a >> b;
        vec.push_back({a,b});
    }
    
    long long cnt=0;
    for(int i=0;i<vec.size();i){
        cnt += vec[i].second - vec[i].first;
        // cout << vec[i].first << " " << vec[i].second << " " << cnt<< '\n';
        int end = vec[i].second;
        int check=0;
        while(i+1 != vec.size() && vec[i+1].first < end){
            cnt += vec[i+1].second - vec[i+1].first;
            // cout << vec[i+1].first << " " << vec[i+1].second << " " << cnt<< " " << end << '\n';
            if(vec[i+1].second < end) cnt-= vec[i+1].second - vec[i+1].first;
            else cnt -= end - vec[i+1].first;
            // cout << vec[i+1].first << " " << vec[i+1].second << " " << cnt<< " " << end << '\n';
            if(vec[i+1].second > end) end = vec[i+1].second;
            i++;
            check=1;
        }
        i++;
    }
    
    cout << cnt;
    
    return 0;
}