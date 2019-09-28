#include <stdio.h>
#include <iostream>

using namespace std;

int main() {

	int N;
	cin >> N;
	int arr[501][501];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> arr[i][j];
		}
	}
	int d1, d2, max;
	for (int i = 1; i < N; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0) {
				max = arr[i][j] + arr[i - 1][j];
			}
			else {
				d1 = arr[i][j] + arr[i - 1][j - 1];
				d2 = arr[i][j] + arr[i - 1][j];
				if (d1 < d2) max = d2;
				else max = d1;
			}
			arr[i][j] = max;
		}
	}
	max = 0;
	for (int i = 0; i < N; i++) {
		if (max < arr[N - 1][i])max = arr[N - 1][i];
	}
	printf("%d\n", max);


	return 0;
}