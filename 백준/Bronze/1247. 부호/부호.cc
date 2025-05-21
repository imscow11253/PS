#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// a, b는 절대값이 더 큰 쪽이 앞으로 오게 한다 (a, b 양수)
int compareAbs(const string &a, const string &b) {
    if (a.length() != b.length()) return a.length() > b.length() ? 1 : -1;
    return a.compare(b);
}
// a와 b는 양수 조건, return a + b (문자열)
string add(const string &a, const string &b) {
    string res;
    int carry = 0, i = a.length()-1, j = b.length()-1;
    while(i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if(i >= 0) sum += a[i--]-'0';
        if(j >= 0) sum += b[j--]-'0';
        res.push_back(sum%10 + '0');
        carry = sum/10;
    }
    reverse(res.begin(), res.end());
    return res;
}
// a >= b (절대값)
// return a-b (문자열)
string sub(const string &a, const string &b) {
    string res;
    int borrow = 0, i = a.length()-1, j = b.length()-1;
    while(i >= 0) {
        int d = a[i]-'0' - borrow;
        if(j >= 0) d -= b[j--]-'0';
        if(d < 0) d += 10, borrow = 1;
        else borrow = 0;
        res.push_back(d+'0');
        i--;
    }
    // 앞에 0 제거
    while(res.size()>1 && res.back()=='0') res.pop_back();
    reverse(res.begin(), res.end());
    return res;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    for(int t=0; t<3; ++t) {
        int n;
        cin >> n;
        string total = "0";
        int sign = 1; // 1이면 +, -1이면 -
        for(int i=0; i<n; ++i) {
            string num;
            cin >> num;
            int cursign = 1;
            if(num[0]=='-') cursign = -1, num = num.substr(1);
            else if(num[0]=='+') num = num.substr(1);
            // total = (sign,total), 새 num = (cursign,num)
            if(total=="0") {
                total = num;
                sign = cursign;
            }
            else if(sign == cursign) {
                total = add(total, num);
            }
            else {
                int cmp = compareAbs(total,num);
                if(cmp == 0) {
                    total = "0";
                    sign = 1;
                } else if(cmp > 0) { // |total| > |num|
                    total = sub(total, num);
                    // sign 바뀌지 않음
                } else {
                    total = sub(num, total);
                    sign = cursign;
                }
            }
        }
        if(total=="0") cout << "0\n";
        else if(sign > 0) cout << "+\n";
        else cout << "-\n";
    }
    return 0;
}