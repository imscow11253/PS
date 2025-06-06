# [Gold V] 치킨 배달 - 15686 

[문제 링크](https://www.acmicpc.net/problem/15686) 

### 성능 요약

메모리: 2032 KB, 시간: 0 ms

### 분류

구현, 브루트포스 알고리즘, 백트래킹

### 제출 일자

2025년 6월 1일 20:05:41

### 문제 설명

<p>크기가 N×N인 도시가 있다. 도시는 1×1크기의 칸으로 나누어져 있다. 도시의 각 칸은 빈 칸, 치킨집, 집 중 하나이다. 도시의 칸은 (r, c)와 같은 형태로 나타내고, r행 c열 또는 위에서부터 r번째 칸, 왼쪽에서부터 c번째 칸을 의미한다. r과 c는 1부터 시작한다.</p>

<p>이 도시에 사는 사람들은 치킨을 매우 좋아한다. 따라서, 사람들은 "<strong>치킨 거리</strong>"라는 말을 주로 사용한다. <strong>치킨 거리</strong>는 집과 가장 가까운 치킨집 사이의 거리이다. 즉, 치킨 거리는 집을 기준으로 정해지며, 각각의 집은 <strong>치킨 거리</strong>를 가지고 있다. <strong>도시의 치킨 거리</strong>는 모든 집의 <strong>치킨 거리</strong>의 합이다.</p>

<p>임의의 두 칸 (r<sub>1</sub>, c<sub>1</sub>)과 (r<sub>2</sub>, c<sub>2</sub>) 사이의 거리는 |r<sub>1</sub>-r<sub>2</sub>| + |c<sub>1</sub>-c<sub>2</sub>|로 구한다.</p>

<p>예를 들어, 아래와 같은 지도를 갖는 도시를 살펴보자.</p>

<pre>0 2 0 1 0
1 0 1 0 0
0 0 0 0 0
0 0 0 1 1
0 0 0 1 2
</pre>

<p>0은 빈 칸, 1은 집, 2는 치킨집이다.</p>

<p>(2, 1)에 있는 집과 (1, 2)에 있는 치킨집과의 거리는 |2-1| + |1-2| = 2, (5, 5)에 있는 치킨집과의 거리는 |2-5| + |1-5| = 7이다. 따라서, (2, 1)에 있는 집의 치킨 거리는 2이다.</p>

<p>(5, 4)에 있는 집과 (1, 2)에 있는 치킨집과의 거리는 |5-1| + |4-2| = 6, (5, 5)에 있는 치킨집과의 거리는 |5-5| + |4-5| = 1이다. 따라서, (5, 4)에 있는 집의 치킨 거리는 1이다.</p>

<p>이 도시에 있는 치킨집은 모두 같은 프랜차이즈이다. 프렌차이즈 본사에서는 수익을 증가시키기 위해 일부 치킨집을 폐업시키려고 한다. 오랜 연구 끝에 이 도시에서 가장 수익을 많이 낼 수 있는  치킨집의 개수는 최대 M개라는 사실을 알아내었다.</p>

<p>도시에 있는 치킨집 중에서 최대 M개를 고르고, 나머지 치킨집은 모두 폐업시켜야 한다. 어떻게 고르면, <strong>도시의 치킨 거리</strong>가 가장 작게 될지 구하는 프로그램을 작성하시오.</p>

### 입력 

 <p>첫째 줄에 N(2 ≤ N ≤ 50)과 M(1 ≤ M ≤ 13)이 주어진다.</p>

<p>둘째 줄부터 N개의 줄에는 도시의 정보가 주어진다.</p>

<p>도시의 정보는 0, 1, 2로 이루어져 있고, 0은 빈 칸, 1은 집, 2는 치킨집을 의미한다. 집의 개수는 2N개를 넘지 않으며, 적어도 1개는 존재한다. 치킨집의 개수는 M보다 크거나 같고, 13보다 작거나 같다.</p>

### 출력 

 <p>첫째 줄에 폐업시키지 않을 치킨집을 최대 M개를 골랐을 때, 도시의 치킨 거리의 최솟값을 출력한다.</p>

 ### 풀이 

 <p>골드5 문제인데 제법 많이 해멨다. 처음엔 각 치킨집 별로 bfs를 돌려서 각 집과의 거리를 구해서 가장 작은 거리의 합을 가진 치킨집 m개만 남기고, 각 집에서 bfs를 돌려서 치킨 거리를 구했는데 이건 완전히 틀린 알고리즘이다. 치킨집에서 집과의 거리의 합이 작은게 치킨거리를 작게하는 치킨집이라는 보장이 없기 때문이다. 태그를 보니 백트래킹이었다. 치킨집이 13개 최대니까 13Cm 이라는 조합을 계산해도 치간초과가 나지 않는다. 조합을 처음엔 set에 담아 두는 식으로 로직을 작성했는데 이건 너무 비효율적이어서 시간초과가 났다. vector에 인덱스만 저장해두는 방식으로 수정하니까 성공했다. 아 그리고 처음엔 조합을 완성해두고 bfs를 돌렸는데 이건 굳이 그럴 필요가 없다. 집과 치킨집의 좌표가 다 저장되어 있으니 반복문으로 거리만 계산하면 되는 것이다. </p>

