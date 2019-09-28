#include <iostream>
using namespace std;
int DpOne[41];
int DpZero[41];
int main() {
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		int num;
		scanf("%d", &num);
		DpZero[0] = 1;
		DpZero[1] = 0;
		DpOne[1] = 1;
		DpOne[2] = 1;
		for (int i = 3; i <= num; i++) {
			DpOne[i] = DpOne[i - 1] + DpOne[i - 2];
		}
		for (int i = 2; i <= num; i++) {
			DpZero[i] = DpZero[i - 1] + DpZero[i - 2];
		}
		printf("%d %d\n", DpZero[num], DpOne[num]);
	}
	return 0;
}