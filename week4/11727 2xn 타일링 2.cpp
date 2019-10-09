#include <iostream>
using namespace std;
int d[1001]; // 2 x n 타일 채우는 방법의 수
int solve(int n) {
	d[1] = 1;
	d[2] = 3;
	for (int i = 3; i <= n; i++) {
		d[i] = (d[i - 1]  + (d[i - 2] * 2)) % 10007;
	}
	return d[n];
}
int main() {
	int N;
	scanf("%d", &N);
	printf("%d", solve(N));
	return 0;
}