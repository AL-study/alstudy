/*
#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
	int arr[100001] = { 0 };
	int dis[100001];
	int N;
	cin >> N;
	for (int i = 1; i < N; i++) {
		scanf(" %d", &arr[i]);
	}
	for (int i = 0; i < N; i++) {
		scanf(" %d", &dis[i]);
	}

	long long res = 0;
	int cnt = 1000000000;

	for (int i = 0; i < N - 1; i++) {
		if (cnt > dis[i]) {
			cnt = dis[i];
		}
		long long temp = cnt * arr[i + 1];
		res += temp;
	}

	printf("%lld\n", res);


	return 0;
}
*/