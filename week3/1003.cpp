#include <stdio.h>
#include <iostream>

using namespace std;

int arr[41];

int fib(int n) {
	if (n == 0) {
		return arr[0] = 0;
	}
	else if (n == 1) {
		return arr[1] = 1;
	}
	else {
		if (arr[n]) return arr[n];
		else return arr[n] = fib(n - 1) + fib(n - 2);
	}
}

int main() {
	int T;
	cin >> T;
	fib(40);

	for (int t = 0; t < T; t++) {
		int n;
		cin >> n;
		if (n == 0) {
			printf("1 0\n");
		}
		else {
			printf("%d %d\n", arr[n-1], arr[n]);
		}
	}

	return 0;
}