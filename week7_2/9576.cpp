/*
#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second) return a.first > b.first;
	return a.second > b.second;
}

int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int N, M;
		scanf(" %d %d", &N, &M);
		pair<int, int> arr[1001];
		for (int i = 0; i < M; i++) {
			scanf(" %d %d", &arr[i].first, &arr[i].second);
		}
		sort(arr, arr + M, compare);
		int cnt = N;
		for (int i = 0; i < M; i++) {
			if (arr[i].second >= cnt && arr[i].first <= cnt) {
				cnt--;
			}
		}
		printf("%d\n", N - cnt);
	}

	return 0;
}
*/