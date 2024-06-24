#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int arr[1001][1001];
int lenA, lenB;
string strA, strB;

int main(int argc, char *argv[]) {
	cin >> strA >> strB;

	lenA = strA.length(), lenB = strB.length();

	for (int i = 1; i <= lenA; i++)
		for (int j = 1; j <= lenB; j++)
			if (strA[i - 1] == strB[j - 1])
				arr[i][j] = arr[i - 1][j - 1] + 1;
			else
				arr[i][j] = max(arr[i - 1][j], arr[i][j - 1]);

	cout << arr[lenA][lenB] << endl;

	return 0;
}