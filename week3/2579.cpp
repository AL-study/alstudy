#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
	int N;
	cin >> N;
	int arr[301] = { 0 };
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	int sum[301] = { 0 };

	sum[0] = arr[0];

	if (arr[0] + arr[1] > arr[1]) sum[1] = arr[0] + arr[1];
	else sum[1] = arr[1];

	if (arr[0] + arr[2] > arr[1] + arr[2]) sum[2] = arr[0] + arr[1];
	else sum[2] = arr[1] + arr[2];

	for (int i = 3; i <= N; i++) {
		if (sum[i - 3] + arr[i - 1] + arr[i] > sum[i - 2] + arr[i]) sum[i] = sum[i - 3] + arr[i-1] + arr[i];
		else sum[i] = sum[i - 2] + arr[i];
	}

	printf("%d\n", sum[N]);
	

	return 0;
}