#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int n;
string trash[10000];
int p,c,v,s,g,f,o;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> trash[i];
    }
    
    cin >> p >> c >> v >>s >> g>>f >> o;
    
    long long result =0;
    bool nomal;
    for(int i =0;i<n;i++){
        string str = trash[i];
        nomal = false;
        for(int i =0;i<str.length()-1;i++){
            if(str[i] != str[i+1]) {nomal = true;break;}
        }
        
        if(nomal){
            result += o * str.length();
        } else{
            switch(str[0]){
                case 'P':
                    result += min(p * str.length(), o * str.length());
                    break;
                case 'C':
                    result += min(c * str.length(), o * str.length());
                    break;
                case 'V':
                    result += min(v * str.length(), o * str.length());
                    break;
                case 'S':
                    result += min(s * str.length(), o * str.length());
                    break;
                case 'G':
                    result += min(g * str.length(), o * str.length());
                    break;
                case 'F':
                    result += min(f * str.length(), o * str.length());
                    break;
                case 'O':
                    result += min(o * str.length(), o * str.length());
                    break;
            }
        }
        // cout << result << '\n';
    }
    
    cout << result;
    
    return 0;
}