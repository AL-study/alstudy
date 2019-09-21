#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int N;
int arr[20][20];

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	int check[20] = { 0 };
	int cnt = 1;
	for (int i = 0; i < N / 2; i++) {
		check[i] = 1;
		cnt *= 2;
	}
	sort(check, check + N);
	int min = 0x7FFFFFFF;
	do {
		if (cnt == N / 2)break;
		int sum0 = 0, sum1 = 0, res;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (i == j) continue;
				if (check[i]) {
					if (check[j]) {
						sum1 += arr[i][j];
					}
				}
				else {
					if (!check[j]) {
						sum0 += arr[i][j];
					}
				}
			}
		}
		res = abs(sum0 - sum1);
		if (min > res) min = res;
		cnt++;

	} while (next_permutation(check, check + N));

	printf("%d\n", min);

	return 0;
}