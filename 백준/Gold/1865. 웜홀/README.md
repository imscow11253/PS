# [Gold III] 웜홀 - 1865 

[문제 링크](https://www.acmicpc.net/problem/1865) 

### 성능 요약

메모리: 2308 KB, 시간: 40 ms

### 분류

그래프 이론, 최단 경로, 벨만–포드

### 제출 일자

2025년 5월 14일 22:38:22

### 문제 설명

<p>때는 2020년, 백준이는 월드나라의 한 국민이다. 월드나라에는 N개의 지점이 있고 N개의 지점 사이에는 M개의 도로와 W개의 웜홀이 있다. (단 도로는 방향이 없으며 웜홀은 방향이 있다.) 웜홀은 시작 위치에서 도착 위치로 가는 하나의 경로인데, 특이하게도 도착을 하게 되면 시작을 하였을 때보다 시간이 뒤로 가게 된다. 웜홀 내에서는 시계가 거꾸로 간다고 생각하여도 좋다.</p>

<p>시간 여행을 매우 좋아하는 백준이는 한 가지 궁금증에 빠졌다. 한 지점에서 출발을 하여서 시간여행을 하기 시작하여 다시 출발을 하였던 위치로 돌아왔을 때, 출발을 하였을 때보다 시간이 되돌아가 있는 경우가 있는지 없는지 궁금해졌다. 여러분은 백준이를 도와 이런 일이 가능한지 불가능한지 구하는 프로그램을 작성하여라.</p>

### 입력 

 <p>첫 번째 줄에는 테스트케이스의 개수 TC(1 ≤ TC ≤ 5)가 주어진다. 그리고 두 번째 줄부터 TC개의 테스트케이스가 차례로 주어지는데 각 테스트케이스의 첫 번째 줄에는 지점의 수 N(1 ≤ N ≤ 500), 도로의 개수 M(1 ≤ M ≤ 2500), 웜홀의 개수 W(1 ≤ W ≤ 200)이 주어진다. 그리고 두 번째 줄부터 M+1번째 줄에 도로의 정보가 주어지는데 각 도로의 정보는 S, E, T 세 정수로 주어진다. S와 E는 연결된 지점의 번호, T는 이 도로를 통해 이동하는데 걸리는 시간을 의미한다. 그리고 M+2번째 줄부터 M+W+1번째 줄까지 웜홀의 정보가 S, E, T 세 정수로 주어지는데 S는 시작 지점, E는 도착 지점, T는 줄어드는 시간을 의미한다. T는 10,000보다 작거나 같은 자연수 또는 0이다.</p>

<p>두 지점을 연결하는 도로가 한 개보다 많을 수도 있다. 지점의 번호는 1부터 N까지 자연수로 중복 없이 매겨져 있다.</p>

### 출력 

 <p>TC개의 줄에 걸쳐서 만약에 시간이 줄어들면서 출발 위치로 돌아오는 것이 가능하면 YES, 불가능하면 NO를 출력한다.</p>


 ### 출력 

 <p>진짜 삽질 엄청 많이한 코드이다. 우선 벨만-포드 알고리즘을 처음 써봤기에 공부를 한다고 좀 오래 걸렸다. 구현하는 것도 처음이라 좀 걸렸다. 그 다음 시작 노드를 명시하지 않아서 모든 노드를 시작점으로 두고 각각 벨만-포드 알고리즘을 돌리니까 시간초과가 떴다. 한 번만 돌려서 할 수 있다길래 찾아서 해봤는데 계속 틀렸다. 결국 가상의 점인 0번 노드를 두고 모든 노드와의 edge를 가중치 0으로 추가해서 해결했다. GPT가 알려줌. </p>

