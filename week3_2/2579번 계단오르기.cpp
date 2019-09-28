#include <iostream>
using namespace std;
int D[10001];
int stairScore[10001];
int max(int a, int b) {
	if (a > b) return a;
	else return b;
}
int main() {
	int N;
	scanf("%d", &N);
	
	for (int i = 1; i <= N; i++) {
		scanf("%d", &stairScore[i]);
	}
	D[1] = stairScore[1];
	D[2] = stairScore[1] + stairScore[2];

	for (int i = 3; i <= N; i++) {
		D[i] = max((D[i - 3] + stairScore[i - 1] + stairScore[i]), D[i - 2] + stairScore[i]);
	}

	printf("%d\n", D[N]);
	return 0;
}