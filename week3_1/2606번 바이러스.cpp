#include <iostream>
#include <string>
using namespace std;
int connected[101][101]; //컴퓨터 연결정보
int N;
int pairCnt;
int ans;
int visit[101];
void dfs(int computerNumber) {
	visit[computerNumber] = 1;
	ans++;
	for (int i = 1; i <= N; i++) {
		if (connected[computerNumber][i] == 1 && !visit[i]) {
			dfs(i);
		}
	}
}
int main()
{
	scanf("%d", &N);
	scanf("%d", &pairCnt);
	for (int i = 0; i < pairCnt; i++) {
		int num1, num2;
		scanf("%d %d", &num1, &num2);
		connected[num1][num2] = 1;
		connected[num2][num1] = 1;
	}

	dfs(1);

	printf("%d\n", ans - 1);
	return 0;
}