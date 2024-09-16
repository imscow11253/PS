#include <iostream>
#include <vector>

using namespace std;

void josephus_permutation(int N, int K) {
    vector<int> people;
    for (int i = 1; i <= N; ++i) {
        people.push_back(i);  // 1부터 N까지 사람들을 벡터에 추가
    }
    
    vector<int> result;  // 결과를 저장할 벡터
    int idx = 0;  // 현재 제거할 사람의 인덱스
    
    while (!people.empty()) {
        idx = (idx + K - 1) % people.size();  // K번째 사람의 인덱스 계산
        result.push_back(people[idx]);  // 제거된 사람을 결과에 추가
        people.erase(people.begin() + idx);  // 제거된 사람을 벡터에서 삭제
    }
    
    // 결과를 원하는 형식으로 출력
    cout << "<";
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i];
        if (i != result.size() - 1) {
            cout << ", ";
        }
    }
    cout << ">" << endl;
}

int main() {
    int N, K;
    cin >> N >> K;  // N과 K 입력받기
    
    josephus_permutation(N, K);  // 요세푸스 순열 계산 및 출력
    
    return 0;
}