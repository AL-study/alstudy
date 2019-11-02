#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;
	int arr[1000][3];
	int dp[1000][3] = { 0 };
	for (int i = 0; i < N; i++) {
		scanf(" %d %d %d", &arr[i][0], &arr[i][1], &arr[i][2]);
	}
	for (int i = 0; i < 3; i++) dp[0][i] = arr[0][i];

	for (int i = 1; i < N; i++) {
		dp[i][0] = min(arr[i][0] + dp[i - 1][1], arr[i][0] + dp[i - 1][2]);
		dp[i][1] = min(arr[i][1] + dp[i - 1][0], arr[i][1] + dp[i - 1][2]);
		dp[i][2] = min(arr[i][2] + dp[i - 1][0], arr[i][2] + dp[i - 1][1]);
	}
	int res = min(dp[N - 1][0], dp[N - 1][1]);
	res = min(res, dp[N - 1][2]);
	printf("%d\n", res);

	return 0;
}