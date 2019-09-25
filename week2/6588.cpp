#include <stdio.h>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int arr[1000002];

void f(int k) {
	for (int i = 2; i <= sqrt(k); i++) {
		if (!arr[i]) continue;
		for (int j = i * 2; j <= k; j += i) {
			arr[j] = 0;
		}
	}
}

int main() {
	int N = 1000001;
	for (int i = 2; i <= N; i++) {
		arr[i] = i;
	}
	f(N);

	while (1) {
		scanf(" %d", &N);
		if (N == 0)break;	

		int i, res = 0;
		for (i = 2; i <= (N / 2) + 1; i++) {
			if (arr[i] == 0) continue;
			res = N - arr[i];
			if (arr[res])break;
		} 
		if (i == (N / 2) + 1) {
			printf("Goldbach's conjecture is wrong.\n");
		}
		else {
			printf("%d = %d + %d\n", N, arr[i], arr[res]);
		}
	}
	return 0;
}