# [Platinum V] Counting Inversions - 10090 

[문제 링크](https://www.acmicpc.net/problem/10090) 

### 성능 요약

메모리: 13616 KB, 시간: 180 ms

### 분류

자료 구조, 분할 정복, 세그먼트 트리, 정렬

### 제출 일자

2024년 9월 14일 15:22:06

### 문제 설명

<p>A permutation of integers from 1 to n is a sequence a<sub>1</sub>, a<sub>2</sub>, ..., a<sub>n</sub>, such that each integer from 1 to n is appeared in the sequence exactly once.</p>

<p>Two integers in а permutation form an inversion, when the bigger one is before the smaller one.</p>

<p>As an example, in the permutation 4 2 7 1 5 6 3, there are 10 inversions in total. They are the following pairs: 4–2, 4–1, 4–3, 2–1, 7–1, 7–5, 7–6, 7–3, 5–3, 6–3.</p>

<p>Write program invcnt that computes the number of the inversions in a given permutation.</p>

### 입력 

 <p>The value for the number n is written on the first line of the standard input. The permutation is written on the second line: n numbers, delimited by spaces.</p>

### 출력 

 <p>Write the count of inversions on the standard output.</p>
 
 ### 풀이 

 <p>어제 교내 알고리즘 동아리에서 분할정복 세미나를 들으면서 소개 받았던 문제다. 플레문제라서 로직이 엄청 복잡하고 어려울 줄 알았는데 로직이 복잡하다기 보단, 이 문제에서 merge sort를 생각해내는 것이 쉽지 않은 것 같다. 

merge sort를 이런 식으로 활용할 수 있다는 점이 신기했다. merge하는 과정에서 오른쪽 배열에서 선택이 되면 왼쪽 배열에 남아있는 부분이 inversion counting 된다는 개념으로 풀었다. 

counting inversion  형식을 좀 알고 있으면 다양한 응용 분야에도 쓰일 수 있다는 것을 기억해두도록 하자. 비슷한 문제로 bubble sort에서 swap이 얼마나 되는지 세는 문제도 있다.

이걸 세그먼트 트리로도 풀 수 있다는데 그건 다음주 세미나 주제다. 처음 접하는 개념이라 나중에 이 문제를 세그먼트 트리로도 풀어보려고 한다.</p>

