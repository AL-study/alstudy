/*
#include <stdio.h>
#include <iostream>
#include <cmath>
#include <algorithm>

#define N 2000001

using namespace std;


int arr[N + 1];

void f(int k = N) {

	for (int i = 2; i < N; i++) {
		arr[i] = i;
	}

	for (int i = 2; i <= sqrt(k); i++) {
		if (!arr[i]) continue;
		for (int j = i * 2; j <= k; j += i) {
			arr[j] = 0;
		}
	}
}

int main() {
	f();

	int tc;
	cin >> tc;

	for (int t = 0; t < tc; t++) {
		long long a, b, sum;
		scanf("%lld %lld", &a, &b);
		sum = a + b;
		bool check = false;
		if (sum % 2 == 0) {
			if (sum >= 4) check = true;
		}
		else {
			long long test = sum - 2;
			check = true;
			for (int i = 0; i < N; i++) {
				if (arr[i] == 0) continue;
				if (arr[i] == test) break;
				if (test % arr[i] == 0) {
					check = false;
					break;
				}
			}
		}

		if (check)printf("YES\n");
		else printf("NO\n");

	}
	return 0;
}
*/