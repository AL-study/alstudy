#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b) {
	if (a % b) return gcd(b, a % b);
	return b;
}

int main() {
	int N;
	cin >> N;
	
	int arr[100001];
	int g = 0, cnt;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		if (i)
			g = gcd(g, arr[i] - arr[i - 1]);
	}
	cnt = (arr[N - 1] - arr[0]) / g - N + 1;
	printf("%d\n", cnt);

	return 0;
}