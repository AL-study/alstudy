#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

int N, K;
bool visited[100001];

int bfs() {
	queue<pair<int, int> > q;
	q.push({ N,0 });
	while (!q.empty()) {
		int s = q.front().first;
		int cnt = q.front().second;
		q.pop();
		if (s == K) return cnt;
		if (visited[s]) continue;
		visited[s] = true;
		
		if (s + 1 >= 0 && s + 1 <= 100000) {
			q.push({ s + 1, cnt + 1 });
		}
		if (s - 1 >= 0 && s - 1 <= 100000) {
			q.push({ s - 1, cnt + 1});
		}
		if (s * 2 >= 0 && s * 2 <= 100000) {
			q.push({ s * 2, cnt + 1});
		}
	}

}

int main() {
	
	cin >> N >> K;

	printf("%d\n", bfs());


	return 0;
}