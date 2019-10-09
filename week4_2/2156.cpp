/*
#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {

	int n;
	int arr[10001];
	int sum[10001] = { 0 };

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sum[0] = arr[0];

	sum[1] = max(arr[0] + arr[1], arr[1]);

	sum[2] = max(arr[0] + arr[2], arr[1] + arr[2]);
	
	for (int i = 3; i < n - 1; i++) {
		sum[i] = max(sum[i - 3] + arr[i - 1] + arr[i], sum[i - 2] + arr[i]);
	}

	int temp = max(sum[n - 4] + arr[n - 2] + arr[n - 1], sum[n - 3] + arr[n - 1]);
	temp = max(temp, sum[n - 3] + arr[n - 2]);
	sum[n - 1] = max(temp, sum[n - 4] + arr[n - 2]);

	printf("%d\n", sum[n - 1]);

	return 0;
}
*/