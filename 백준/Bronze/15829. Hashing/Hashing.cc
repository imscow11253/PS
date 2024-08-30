#include <iostream>
#include <string>

using namespace std;

const int divide = 1234567891;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    string str;
    cin >> str;
    
    long long cnt = 0;
    long long power = 1; 
    
    for (char a : str) {
        int char_value = a - 'a' + 1; 
        
        power = power % divide;
        
        cnt = (cnt + char_value * power) % divide;
        
        power = power *31  % divide;
    }
    
    cout << cnt;

    return 0;
}
