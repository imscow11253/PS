# [Gold IV] 특정한 최단 경로 - 1504 

[문제 링크](https://www.acmicpc.net/problem/1504) 

### 성능 요약

메모리: 20208 KB, 시간: 116 ms

### 분류

그래프 이론, 최단 경로, 데이크스트라

### 제출 일자

2025년 5월 10일 17:05:18

### 문제 설명

<p>방향성이 없는 그래프가 주어진다. 세준이는 1번 정점에서 N번 정점으로 최단 거리로 이동하려고 한다. 또한 세준이는 두 가지 조건을 만족하면서 이동하는 특정한 최단 경로를 구하고 싶은데, 그것은 바로 임의로 주어진 두 정점은 반드시 통과해야 한다는 것이다.</p>

<p>세준이는 한번 이동했던 정점은 물론, 한번 이동했던 간선도 다시 이동할 수 있다. 하지만 반드시 최단 경로로 이동해야 한다는 사실에 주의하라. 1번 정점에서 N번 정점으로 이동할 때, 주어진 두 정점을 반드시 거치면서 최단 경로로 이동하는 프로그램을 작성하시오.</p>

### 입력 

 <p>첫째 줄에 정점의 개수 N과 간선의 개수 E가 주어진다. (2 ≤ N ≤ 800, 0 ≤ E ≤ 200,000) 둘째 줄부터 E개의 줄에 걸쳐서 세 개의 정수 a, b, c가 주어지는데, a번 정점에서 b번 정점까지 양방향 길이 존재하며, 그 거리가 c라는 뜻이다. (1 ≤ c ≤ 1,000) 다음 줄에는 반드시 거쳐야 하는 두 개의 서로 다른 정점 번호 v<sub>1</sub>과 v<sub>2</sub>가 주어진다. (v<sub>1</sub> ≠ v<sub>2</sub>, v<sub>1</sub> ≠ N, v<sub>2</sub> ≠ 1) 임의의 두 정점 u와 v사이에는 간선이 최대 1개 존재한다.</p>

### 출력 

 <p>첫째 줄에 두 개의 정점을 지나는 최단 경로의 길이를 출력한다. 그러한 경로가 없을 때에는 -1을 출력한다.</p>

 ### 풀이 

 <p>이건 최단경로 문제인데 좀 특별하다. 특정 노드 2개를 필수적으로 지나야 하는 것이다. 바로 플로이드 워셜이 떠올랐다. dp를 계산할 때 그런 식으로 계산하기 때문이다. 하지만 node가 800개 일 수 있어서 n^3 하면 메모리 초과가 뜬다. 그래서 다익스트라로 풀어야 한다. 특정 노드를 무조건 지나야 하니까 v1,v2 에서 각각 다익스트라를 돌렸다. 그러면 v1,v2에서 시작점, 끝점, v1-v2 간의 최단거리가 나오기 때문에 이 조합에서 최솟값을 찾으면 된다. 근데 시간초과가 한 번 떴다. 다이스트라는 모든 노드까지의 거리를 계산하기 때문에 내가 찾고자 하는 노드까지의 거리를 찾아내면 미리 종료하도록 하니까 통과했다. </p>

