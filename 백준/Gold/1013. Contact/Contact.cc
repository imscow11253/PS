#include <iostream>
#include <regex>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    regex pattern("(100+1+|01)+");

    while(t--) {
        string str;
        cin >> str;

        if(regex_match(str, pattern))
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}