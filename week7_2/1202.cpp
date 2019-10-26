/*
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

class j {
public:
	int m, v;
	j() {}
	j(int m, int v) {
		this->m = m;
		this->v = v;
	}
	bool operator < (const j& a) const {
		return this->m < a.m;
	}
};

int main() {
	int N, K;
	cin >> N >> K;
	//j arr[300001];
	//int brr[300001];
	j arr[101];
	int brr[101];

	for (int i = 0; i < N; i++) {
		int a, b;
		scanf(" %d %d", &a, &b);
		arr[i] = j(a, b);
	}
	for (int i = 0; i < K; i++) {
		int a;
		scanf(" %d", &a);
		brr[i] = a;
	}
	
	sort(arr, arr + N);
	sort(brr, brr + K);

	priority_queue<int> q;
	int cnt = 0, res = 0;
	for (int i = 0; i < K; i++) {
		if (cnt < N) {
			while (arr[cnt].m <= brr[i]) {
				q.push(arr[cnt].v);
				cnt++;
				if (cnt == N) {
					break;
				}
			}
		}
		res += q.top();
		q.pop();
	}

	printf("%d\n", res);

	return 0;
}
*/