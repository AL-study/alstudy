#include <iostream>
using namespace std;
int max(int a, int b) {
	if(a > b) return a;
	else return b;
}
int arr[501][501];
int D[501][501];
int main() {
	int N;
	int res = -1e10;

	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	D[1][1] = arr[1][1]; 
	for (int i = 2; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			D[i][j] = max((D[i - 1][j - 1] + arr[i][j]), (D[i - 1][j] + arr[i][j]));
		}
	}
	
	for (int i = 1; i <= N; i++) {
		if (D[N][i] > res) {
			res = D[N][i];
		}
	}

	printf("%d\n", res);
	return 0;
}