#include <iostream>

using namespace std;

long long travel(long long x){
	if(x==1) return 0;
	long long index;
	for(index=1;index+index<x;index+=index);
	return !travel(x-index);
}

int main() {
	long long n;
	cin>>n;
	
	cout<<travel(n);
	return 0;
}
