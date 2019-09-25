#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int N;
int M;
int visit[1001];
queue<int> q;
vector<int> connectedInfo[1001];
void dfs(int now) {
	visit[now] = 1;
	printf("%d ", now);
	int nowConnectedSize = connectedInfo[now].size();
	for (int i = 0; i < nowConnectedSize; i++) {
		if (!visit[connectedInfo[now][i]]) {
			dfs(connectedInfo[now][i]);
		}
	}
}
void bfs(int start) {
	visit[start] = 1;
	q.push(start);
	while (!q.empty()) {
		int front = q.front();
		printf("%d ", front);
		q.pop();
		int connectedSize = connectedInfo[front].size();
		for (int i = 0; i < connectedSize; i++) {
			int tmp = connectedInfo[front][i];
			if (!visit[tmp]) {
				visit[tmp] = 1;
				q.push(tmp);
			}
		}
	}
}
int main() {
	int start;
	scanf("%d %d %d", &N, &M, &start);
	for (int i = 0; i < M; i++) {
		int num1, num2;
		scanf("%d %d", &num1, &num2);
		connectedInfo[num1].push_back(num2);
		connectedInfo[num2].push_back(num1);
	}

	for (int i = 1; i <= N; i++) {
		sort(connectedInfo[i].begin(), connectedInfo[i].end());
	}

	dfs(start);
	memset(visit, 0, sizeof(visit));
	printf("\n");
	bfs(start);
	return 0;
}