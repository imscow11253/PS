#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

int main() {
    // 현재 시스템 시간(UTC) 가져오기
    time_t now = time(0);
    
    // UTC 시간에 9시간을 더해 KST로 변환
    now += 9 * 60 * 60;
    
    // 변환된 시간을 tm 구조체로 변환
    tm *ltm = gmtime(&now);

    // YYYY-MM-DD 형식으로 출력
    cout << 1900 + ltm->tm_year << "-";  // 연도 출력
    cout << setw(2) << setfill('0') << 1 + ltm->tm_mon << "-";  // 월 출력 (1월이 0이므로 +1)
    cout << setw(2) << setfill('0') << ltm->tm_mday << endl;  // 일 출력

    return 0;
}