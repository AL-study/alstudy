#include <stdio.h>
#include <iostream>

using namespace std;

int N, cnt;
int arr[15][15];

bool promising(int y, int x) {
	for (int i = 0; i < y; i++) {
		if (arr[i][x]) return false;
		int c = y - i;
		if (x - c >= 0)
			if (arr[i][x - c]) return false;
		if (x + c < N)
			if (arr[i][x + c]) return false;
	}
	return true;
}

void find(int i) {

	if (i == N) {
		cnt++;
		return;
	}

	for (int j = 0; j < N; j++) {
		arr[i][j] = 1;
		if (promising(i, j)) {
			find(i + 1);
		}
		arr[i][j] = 0;
	}

}

int main() {

	cin >> N;

	find(0);

	printf("%d\n", cnt);

	return 0;
}