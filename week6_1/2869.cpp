#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
	int A, B, V;
	cin >> A >> B >> V;
	int cnt = 1, temp = V - A;
	if (temp > 0) {
		int res = A - B;
		cnt += (temp + res - 1) / res;
	};
	printf("%d\n", cnt);

	return 0;
}