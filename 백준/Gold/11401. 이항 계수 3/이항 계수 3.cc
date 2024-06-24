#include <iostream>

using namespace std;

long long int P = 1000000007;

long long int power(long long int a, long long int po){
    if(po==1) return a%P;
    long long int re = power(a, po/2);
    re = (re*re)%P;
    if(po%2==1) re = (re*a)%P;
    return re%P;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N,R;
    cin >> N >> R;
    
    //모듈러 연산을 이용해서 N!%P 구하기
    long long int factN=1;
    for(int i =1;i<=N;i++){
        factN *= i%P;
        factN %=P;
    }
    
    //모듈러 연산을 이용해서 {R!(N-R)!} %P 구하기
    long long int factR=1;
    for(int j=1;j<=R;j++){
        factR *= j%P;
        factR %= P;
    }
    for(int j=1;j<=N-R;j++){
        factR *= j%P;
        factR %= P;
    }
    
    //분할정복으로 R!^P-2와 (N_R)!^P-2 구하기
    factR = power(factR, P-2);
    
    int re = (factR * factN) %P;
    
    cout << re << '\n';
    
    return 0;
}