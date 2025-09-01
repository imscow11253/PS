# [Gold I] 합 - 1081 

[문제 링크](https://www.acmicpc.net/problem/1081) 

### 성능 요약

메모리: 2020 KB, 시간: 0 ms

### 분류

수학

### 제출 일자

2025년 9월 1일 16:25:19

### 문제 설명

<p>L보다 크거나 같고, U보다 작거나 같은 모든 정수의 각 자리의 합을 구하는 프로그램을 작성하시오.</p>

### 입력 

 <p>첫째 줄에 두 정수 L과 U이 주어진다.</p>

### 출력 

 <p>첫째 줄에 문제의 정답을 출력한다.</p>

 ### 풀이 

 <p>누적합, 수학 문제였다. 규칙 기반으로 풀다가 모르겠어서 GPT한테 물어보았다. 풀이는 다음과 같다. </p>

 ```cpp
#include <iostream>
using namespace std;

// 1부터 n까지 모든 수의 각 자리수의 합을 구하는 함수
long long digitSumUpto(long long n) {
    long long sum = 0, factor = 1;
    while (n / factor > 0) {
        long long high = n / (factor * 10);            // 현재 자리보다 높은 자리(상위)
        int cur = (n / factor) % 10;                   // 현재 자리의 숫자(0~9)
        long long low = n % factor;                    // 현재 자리보다 낮은 자리(하위)

        // 1. 상위 숫자가 만든 누적: high * 45 * factor
        //    (0~9의 각 숫자가 해당 자리에 factor번씩 등장)
        sum += high * 45 * factor;

        // 2. 현재 자리의 숫자가 만든 누적: cur*(cur-1)/2 * factor
        //    (0~cur-1 까지 각 숫자가 factor번씩 등장)
        sum += cur * (cur - 1) / 2 * factor;

        // 3. 현재 자리 숫자로 시작하는 아래 부분: cur * (low + 1)
        //    (현재 자리수가 cur일 때 그 아래 모든 경우)
        sum += cur * (low + 1);

        factor *= 10;
    }
    return sum;
}

int main() {
    long long a, b;
    cin >> a >> b;
    cout << digitSumUpto(b) - digitSumUpto(a - 1) << endl;
}
```

