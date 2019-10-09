#include <stdio.h>
#include <iostream>

using namespace std;


int main() {
	int N;
	int arr[100001];
	int sum[100001] = { 0 };
	cin >> N;
	int max = 0x80000000;
	for (int i = 1; i <= N; i++) {
		scanf(" %d", &arr[i]);
		if (sum[i - 1] + arr[i] > arr[i]) {
			sum[i] = sum[i - 1] + arr[i];
		}
		else {
			sum[i] = arr[i];
		}
		if (max < sum[i]) max = sum[i];
	}

	printf("%d\n", max);

	return 0;
}