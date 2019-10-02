/*
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int arr[100001];
int visited[100001];
vector<int> v;
vector<int> temp;
vector<int>::iterator it;

void dfs(int start, int now) {
	if (start == now) {
		while (!temp.empty()) {
			int n = temp.back();
			temp.pop_back();
			if (visited[n]) continue;
			visited[n] = true;
			v.push_back(n);
		}
		return;
	}

	it = find(temp.begin(), temp.end(), now);

	if (it != temp.end()) return;

	if (now == 0) {
		temp.push_back(start);
		dfs(start, arr[start]);
	}
	else {
		temp.push_back(now);
		dfs(start, arr[now]);
	}

}

int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> N;
		for (int i = 1; i <= N; i++) {
			cin >> arr[i];
			visited[i] = false;
		}
		for (int i = 1; i <= N; i++) {
			dfs(i, 0);
			temp.clear();
		}
		int cnt = N - v.size();
		v.clear();

		printf("%d\n", cnt);
	}

	return 0;
}
*/