#include <iostream>
using namespace std;
int dp[1000001];
int min(int a, int b) {
	if (a < b) {
		return a;
	}
	else return b;
}
int main() {
	int num;
	dp[1] = 0;
	dp[2] = 1;
	scanf("%d", &num);

	for (int i = 2; i <= num; i++) {
		if (i % 3 == 0) {
			dp[i] = min(dp[i / 3], dp[i - 1]) + 1;
		}
		else if (i % 2 == 0) {
			dp[i] = min(dp[i / 2], dp[i - 1]) + 1;
		}
		else {
			dp[i] = dp[i - 1] + 1;
		}
	}
	printf("%d", dp[num]);
	return 0;
}