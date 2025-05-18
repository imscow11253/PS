#include <iostream>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int g, m;
    string w, s;
    cin >> g >> m >> w >> s;

    int need[256] = {}, window[256] = {};

    for(char c : w) ++need[(unsigned char)c];

    for(int i = 0; i < g; ++i)
        ++window[(unsigned char)s[i]];

    int answer = 0;
    // 첫 창
    bool flag = true;
    for(int c = 0; c < 256; ++c)
        if(need[c] != window[c]) flag = false;
    if(flag) ++answer;

    // 나머지 창
    for(int i = g; i < m; ++i) {
        --window[(unsigned char)s[i-g]];
        ++window[(unsigned char)s[i]];
        flag = true;
        for(int c = 0; c < 256; ++c)
            if(need[c] != window[c]) {flag = false; break;}
        if(flag) ++answer;
    }

    cout << answer << "\n";
    return 0;
}