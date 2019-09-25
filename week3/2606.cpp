#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N;
vector<int> v[101];
bool visited[101];

int bfs() {
	int cnt =0;
	queue<int> q;
	q.push(1);
	while (!q.empty()) {
		int siz, cur = q.front();
		q.pop();
		if (visited[cur])continue;
		visited[cur] = true;
		siz = v[cur].size();
		for (int i = 0; i < siz; i++) {
			q.push(v[cur][i]);
		}
		cnt++;
	}

	return cnt - 1;
}


int main() {

	cin >> N;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	printf("%d\n", bfs());

	return 0;
}