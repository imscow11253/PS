#include <iostream>
#include <vector>

using namespace std;

int n,m,c;
int color_num[10] = {0,};
vector<int> vec;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m >>c;
    for(int i =1;i<=c;i++){
        cin >> color_num[i];
    }
    
    int direction =1;
    for(int i =1;i<=c;i++){
        while(color_num[i]--){
            vec.push_back(i);
            if(vec.size() == m){
                if(direction){
                    for(int a :vec) cout << a;
                    cout << '\n';
                    vec.clear();
                    direction = 0;
                }
                else{
                    for(int i = m-1;i>=0;i--) cout << vec[i];
                    cout << '\n';
                    vec.clear();
                    direction =1;
                }
            }
        }
    }
    
    return 0;
}