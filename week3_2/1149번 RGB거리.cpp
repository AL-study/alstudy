#include <iostream>
using namespace std;
enum color { RED = 0, GREEN, BLUE };
int D[1001][3];
int cost[1001][3];
int min(int a, int b) {
	if (a < b) return a;
	else return b;
}
int main() {
	int N;
	scanf("%d", &N);
	
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < 3; j++) {
			scanf("%d", &cost[i][j]);
		}
	}
	
	for (int i = 1; i <= N; i++) {
		D[i][RED] = min(D[i - 1][BLUE], D[i - 1][GREEN]) + cost[i][RED];
		D[i][GREEN] = min(D[i - 1][RED], D[i - 1][BLUE]) + cost[i][GREEN];
		D[i][BLUE] = min(D[i - 1][RED], D[i - 1][GREEN]) + cost[i][BLUE];
	}

	int ans = min(min(D[N][RED], D[N][BLUE]), D[N][GREEN]);
	printf("%d\n", ans);
	return 0;
}