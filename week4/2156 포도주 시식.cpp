#include<iostream>
#include<algorithm>
using namespace std;
int d[10001];
int podo[10001];
int solve(int n) {
	// 맨마지막 포도주를 마셨을 때 전칸의 포도주를 마신경우, 안마신 경우 
	// 1. 마신경우 = podo[i] + podo[i-1] + d[i-3];
	// 2. 안마신 경우 = podo[i] + d[i-2]
	// 맨 마지막 포도주를 마시지 않았을때
	// d[n] = d[n-1]
	d[1] = podo[1];
	d[2] = podo[1] + podo[2];
	for (int i = 3; i <= n; i++) {
		int tmp1 = podo[i] + podo[i - 1] + d[i - 3];
		int tmp2 = podo[i] + d[i - 2];
		d[i] = max(tmp1, tmp2);
		d[i] = max(d[i], d[i - 1]);
	}
	return d[n];
}
int main() {
	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &podo[i]);
	}
	printf("%d", solve(N));
	return 0;
}