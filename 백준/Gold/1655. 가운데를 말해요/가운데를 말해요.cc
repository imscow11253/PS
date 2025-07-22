#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n;
priority_queue<int> max_qu;
priority_queue<int, vector<int>, greater<int>> min_qu;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    int temp;
    for(int i =0;i<n;i++){
        cin >> temp;
        if(min_qu.size() ==0  && max_qu.size()==0) max_qu.push(temp);
        else if(min_qu.size() == max_qu.size()){
            if(min_qu.top() < temp){
                min_qu.push(temp);
                max_qu.push(min_qu.top());
                min_qu.pop();
            }
            else{
                max_qu.push(temp);
            }
        }
        else{
            if(max_qu.top() > temp){
                max_qu.push(temp);
                min_qu.push(max_qu.top());
                max_qu.pop();
            }
            else{
                min_qu.push(temp);
            }
        }
        cout << max_qu.top() <<'\n';
    }
    
    return 0;
}