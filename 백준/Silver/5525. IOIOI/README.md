# [Silver I] IOIOI - 5525 

[문제 링크](https://www.acmicpc.net/problem/5525) 

### 성능 요약

메모리: 7588 KB, 시간: 12 ms

### 분류

문자열

### 제출 일자

2025년 4월 24일 21:10:28

### 문제 설명

<p>N+1개의 <code>I</code>와 N개의 <code>O</code>로 이루어져 있으면, <code>I</code>와 <code>O</code>이 교대로 나오는 문자열을 P<sub>N</sub>이라고 한다.</p>

<ul>
	<li>P<sub>1</sub> <code>IOI</code></li>
	<li>P<sub>2</sub> <code>IOIOI</code></li>
	<li>P<sub>3</sub> <code>IOIOIOI</code></li>
	<li>P<sub>N</sub> <code>IOIOI...OI</code> (<code>O</code>가 N개)</li>
</ul>

<p><code>I</code>와 <code>O</code>로만 이루어진 문자열 S와 정수 N이 주어졌을 때, S안에 P<sub>N</sub>이 몇 군데 포함되어 있는지 구하는 프로그램을 작성하시오.</p>

### 입력 

 <p>첫째 줄에 N이 주어진다. 둘째 줄에는 S의 길이 M이 주어지며, 셋째 줄에 S가 주어진다.</p>

### 출력 

 <p>S에 P<sub>N</sub>이 몇 군데 포함되어 있는지 출력한다.</p>

 ### 풀이 

 <p>계산해보니 naive 하게 브루트포스하면 시간초과 난다는 것을 알았다. 좀 10분 고민했다. 누적합? 슬라이딩 윈도우? 어떤 개념인지 명확하지 않은데 그냥 가능한 수를 배열에 계산해두는 방식으로 진행했다. </p>

