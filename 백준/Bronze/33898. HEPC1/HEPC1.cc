#include <iostream>
#include <set>
#include <string>

using namespace std;

set<char> st;
string str[2];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    
    for(int i =0;i<2;i++){
        cin >> str[i];
        for(char a : str[i]) st.insert(a);
    }
    if(st.size() != 4) cout << "NO";
    else{
        if(str[0][0] == 'H' && str[0][1] == 'E' && str[1][0] == 'C' && str[1][1] == 'P') cout << "YES";
        else if(str[0][0] == 'C' && str[0][1] == 'H' && str[1][0] == 'P' && str[1][1] == 'E') cout << "YES";
        else if(str[0][0] == 'P' && str[0][1] == 'C' && str[1][0] == 'E' && str[1][1] == 'H') cout << "YES";
        else if(str[0][0] == 'E' && str[0][1] == 'P' && str[1][0] == 'H' && str[1][1] == 'C') cout << "YES";
        else if(str[0][0] == 'H' && str[0][1] == 'C' && str[1][0] == 'E' && str[1][1] == 'P') cout << "YES";
        else if(str[0][0] == 'C' && str[0][1] == 'P' && str[1][0] == 'H' && str[1][1] == 'E') cout << "YES";
        else if(str[0][0] == 'P' && str[0][1] == 'E' && str[1][0] == 'C' && str[1][1] == 'H') cout << "YES";
        else if(str[0][0] == 'E' && str[0][1] == 'H' && str[1][0] == 'P' && str[1][1] == 'C') cout << "YES";
        else cout <<"NO";
    }
    
    
    return 0;
}