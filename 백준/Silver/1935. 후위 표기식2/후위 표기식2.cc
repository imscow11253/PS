#include <iostream>
#include <stack>
#include <string>
#include <iomanip> // 소수점 둘째 자리 출력을 위한 헤더

using namespace std;

int main() {
    int n; // 피연산자의 개수
    cin >> n;

    string expression; // 후위 표기식
    cin >> expression;

    double values[26]; // A ~ Z에 해당하는 값 저장 배열

    // 각 피연산자에 대응하는 값 입력
    for (int i = 0; i < n; i++) {
        cin >> values[i];
    }

    stack<double> st; // 계산을 위한 스택

    // 후위 표기식을 하나씩 처리
    for (char c : expression) {
        if (c >= 'A' && c <= 'Z') { // 피연산자일 경우
            st.push(values[c - 'A']); // 해당 피연산자의 값을 스택에 저장
        } else { // 연산자일 경우
            // 스택에서 두 개의 피연산자를 꺼낸다
            double b = st.top(); st.pop();
            double a = st.top(); st.pop();
            double result;

            // 연산자에 따라 연산 수행
            if (c == '+') {
                result = a + b;
            } else if (c == '-') {
                result = a - b;
            } else if (c == '*') {
                result = a * b;
            } else if (c == '/') {
                result = a / b;
            }

            // 연산 결과를 다시 스택에 넣는다
            st.push(result);
        }
    }

    // 최종 결과는 스택의 맨 위에 남아 있는 값
    double finalResult = st.top();

    // 소숫점 둘째 자리까지 출력
    cout << fixed << setprecision(2) << finalResult << endl;

    return 0;
}