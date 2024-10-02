#include <iostream>
#include <vector>
#include <numeric>  // for gcd, lcm
using namespace std;

typedef long long ll;

// 최대 공약수 구하는 함수
ll gcd(ll a, ll b) {
    while (b != 0) {
        ll temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// 최소 공배수 구하는 함수
ll lcm(ll a, ll b) {
    return (a * b) / gcd(a, b);
}

int main() {
    int n;
    cin >> n;

    vector<pair<ll, ll>> items(n);

    // 입력 받기
    for (int i = 0; i < n; i++) {
        cin >> items[i].first >> items[i].second;  // 분자, 분모
    }

    // 모든 아이템의 분모에 대한 최소 공배수 구하기
    ll commonDenom = items[0].second;
    for (int i = 1; i < n; i++) {
        commonDenom = lcm(commonDenom, items[i].second);
    }

    // 공통 분모를 기준으로 분자 조정하기
    ll commonNumer = items[0].first * (commonDenom / items[0].second);
    for (int i = 1; i < n; i++) {
        ll newNumer = items[i].first * (commonDenom / items[i].second);
        commonNumer = gcd(commonNumer, newNumer);  // 분자들의 최대 공약수 찾기
    }

    // 최종 출력 (기약분수 형태로)
    ll finalGCD = gcd(commonNumer, commonDenom);
    cout << commonNumer / finalGCD << " " << commonDenom / finalGCD << endl;

    return 0;
}