#include <iostream>
using namespace std;

int main() {
    long long A, B, C;
    cin >> A >> B >> C;

    // 판매 가격이 가변 비용보다 작거나 같으면 손익분기점이 존재하지 않음
    if (C <= B) {
        cout << -1 << endl;
    } else {
        // 손익분기점 계산
        long long breakevenPoint = A / (C - B) + 1;
        cout << breakevenPoint << endl;
    }

    return 0;
}