#include <iostream>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    int sta, end;
    while(t--){
        cin >> sta >> end;
        int result=0;
        for(int i = sta; i<= end;i++){
            string str = to_string(i);
            for(char a : str){
                if(a == '0') result++;
            }
        }
        cout << result << '\n'; 
    }
    
    
    return 0;
}