# [Gold III] UNIST는 무엇의 약자일까? - 17841 

[문제 링크](https://www.acmicpc.net/problem/17841) 

### 성능 요약

메모리: 9904 KB, 시간: 64 ms

### 분류

다이나믹 프로그래밍

### 제출 일자

2024년 8월 19일 22:27:37

### 문제 설명

<p>UNIST는 Ulsan National Institute of Science and Technology의 약자이다. 어느 날 원이는 약자가 UNIST가 되는 다른 단어가 있는지에 대해 궁금해졌다.</p>

<p>단어 a의 길이를 len(a)로 표기하자. N개의 단어 W<sub>1</sub>, W<sub>2</sub>, ..., W<sub>N</sub>이 주어질 때, 단어 W<span style="font-size: 10.8333px;">i</span> (1 ≤ i ≤ N)로부터 앞에서 0글자 이상 len(W<sub>i</sub>)글자 이하 택해서 만든 문자열을 P<sub>i</sub>라 하자. 다시 말해, P<sub>i</sub>는 W<sub>i</sub>의 길이 len(P<sub>i</sub>)인 접두사이다.</p>

<p>P<sub>i</sub> (1 ≤ i ≤ N)들을 적당히 잘 정하여, P<sub>1</sub>+P<sub>2</sub>+...+P<sub>N</sub>이 UNIST가 되도록 하는 경우의 수를 구해보자. 단, 연산 +는 문자열 연결(string concatenation) 연산이다.</p>

### 입력 

 <p>첫 줄에 단어의 수 N이 주어진다.</p>

<p>이후 N개의 줄에 한 줄에 하나씩 N개의 단어 W<sub>1</sub>, W<sub>2</sub>, ..., W<sub>N</sub>가 주어진다.</p>

<p>W<sub>i</sub> (1 ≤ i ≤ N)는 1개 이상의 영문 대문자로만 이루어진 문자열이다.</p>

### 출력 

 <p>P<sub>1</sub>+P<sub>2</sub>+...+P<sub>N</sub>이 UNIST가 되도록 P<sub>1</sub>, P<sub>2</sub>, ..., P<sub>N</sub>을 결정하는 경우의 수를 1,000,000,007로 나눈 나머지를 출력한다.</p>

 ### 풀이 

 <p>너무 어려웠던 문제였다. 일단 대충 어떤 식으로 풀어나가야 할지 전체적인 그림은 잡혔는데 브루트포스 식으로 단순 탐색하면 무조건 시간 초과가 날 것 같았다. 

저번에 풀었던 골드 문제 빨강빨강파랑파랑 풍선 문제랑 비슷한 것 같아서 이분탐색으로 풀리나 싶었는데 도무지 이분탐색은 아니었다. DP 인 것 같은데 도무지 보이질 않았다.

한참 고민해서 dp로 풀었는데 두 번이나 틀렸다. 원인을 모르겠어서 GPT 한테 물어보니 내가 예외 케이스를 잘 보지 못했던 문제였고 해결했다! 

GPT에 그만 의존하자.</p>

