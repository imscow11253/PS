# [Gold V] 루나의 게임 세팅 - 25345 

[문제 링크](https://www.acmicpc.net/problem/25345) 

### 성능 요약

메모리: 17804 KB, 시간: 12 ms

### 분류

조합론, 수학

### 제출 일자

2024년 8월 9일 12:43:48

### 문제 설명

<p>루나와 리나는 타워 건설 게임을 하려고 한다. 타워 건설 게임은 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D43E TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>K</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$K$</span></mjx-container>개의 타워를 사용하는 게임이고 루나는 이 게임을 세팅하려고 한다. </p>

<p>게임 세팅은 서로 다른 높이의 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>개의 타워 중 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D43E TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>K</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$K$</span></mjx-container>개를 선택해 원하는 순서로 일렬로 배치하는 것이다. 이때 앞과 뒤에서 바라볼 때 모든 타워가 최소 한 번은 보여야 한다. 즉, 어떤 타워에 대해서 그보다 높은 타워가 그 타워의 앞쪽과 뒤쪽에 모두 존재하면 안된다는 것이다. </p>

<p>게임 세팅을 하던 루나는 문득 게임을 세팅하는 방법이 얼마나 많을 지가 궁금해졌다. 루나를 도와서 게임 세팅을 하는 경우의 수를 구해보자. </p>

### 입력 

 <p>첫째 줄에는 두 양의 정수 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>과 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D43E TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>K</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$K$</span></mjx-container>가 주어진다.</p>

<p>둘째 줄에는 각각의 타워의 높이 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-msub><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D434 TEX-I"></mjx-c></mjx-mi><mjx-script style="vertical-align: -0.15em;"><mjx-texatom size="s" texclass="ORD"><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c></mjx-mn></mjx-texatom></mjx-script></mjx-msub><mjx-mo class="mjx-n"><mjx-c class="mjx-c2C"></mjx-c></mjx-mo><mjx-msub space="2"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D434 TEX-I"></mjx-c></mjx-mi><mjx-script style="vertical-align: -0.15em;"><mjx-texatom size="s" texclass="ORD"><mjx-mn class="mjx-n"><mjx-c class="mjx-c32"></mjx-c></mjx-mn></mjx-texatom></mjx-script></mjx-msub><mjx-mo class="mjx-n"><mjx-c class="mjx-c2C"></mjx-c></mjx-mo><mjx-mo class="mjx-n" space="2"><mjx-c class="mjx-c22EF"></mjx-c></mjx-mo><mjx-mo class="mjx-n" space="2"><mjx-c class="mjx-c2C"></mjx-c></mjx-mo><mjx-msub space="2"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D434 TEX-I"></mjx-c></mjx-mi><mjx-script style="vertical-align: -0.15em;"><mjx-texatom size="s" texclass="ORD"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-texatom></mjx-script></mjx-msub></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><msub><mi>A</mi><mrow data-mjx-texclass="ORD"><mn>1</mn></mrow></msub><mo>,</mo><msub><mi>A</mi><mrow data-mjx-texclass="ORD"><mn>2</mn></mrow></msub><mo>,</mo><mo>⋯</mo><mo>,</mo><msub><mi>A</mi><mrow data-mjx-texclass="ORD"><mi>N</mi></mrow></msub></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$A_{1}, A_{2}, \cdots, A_{N}$</span></mjx-container>이 공백으로 구분되어 주어진다.</p>

<p>모든 입력은 정수이다.</p>

### 출력 

 <p>게임 세팅을 할 수 있는 경우의 수를 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-msup><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn><mjx-script style="vertical-align: 0.393em;"><mjx-texatom size="s" texclass="ORD"><mjx-mn class="mjx-n"><mjx-c class="mjx-c39"></mjx-c></mjx-mn></mjx-texatom></mjx-script></mjx-msup><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-c2B"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="3"><mjx-c class="mjx-c37"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><msup><mn>10</mn><mrow data-mjx-texclass="ORD"><mn>9</mn></mrow></msup><mo>+</mo><mn>7</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$10^{9}+7$</span></mjx-container>로 나눈 나머지를 출력한다. </p>



### 풀이 

 <p>식을 세우는데에는 별로 어렵지 않았다. 문제를 읽고 차근차근 생각하면 식을 쉽게 도출 해낼 수 있다. 전체 식은 nCk * 2^(k-1) 이라는 것을 알 수 있다. nCk는 n개에서 k개를 고르는 경우이고, 2^(k-1)은 타워를 배열하는 경우이다. 타워를 배열하는 경우가 어떻게 저렇게 나오는가? 가장 긴 것부터 놓는다고 생각하면 그 다음 긴 것을 놓을때는 꼭 이전에 놓았던 타워 (지금 놓으려는 것보다 긴 것) 의 바로 양 옆 중 한 곳에  두어야 한다. Why? 둘 사이에 빈 공간이 있으면 다음 타워들로 채워야 하는데 다음 타워들은 그 두개 보다 작은 타워이기 때문에 성립할 수가 없다. 즉 k-1개의 타워가 2 곳에 둘 수 있으므로 2 * 2 * 2 * 2 …… 하게 된다. 

처음에 조합을 그냥 계산식으로 구하려고 해서 overflow가 났다. c++에서 라이브러리로 제공해주는게 있나 찾아보던중 조합의 경우의 수를 쉽게 DP로 구하는 방법인 **파스칼 삼각형**을 보았다. 이것을 보고 풀어내었다.</p>

