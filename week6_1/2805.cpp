#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int N, M;
	int arr[1001];
	//int arr[1000001];
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}
	sort(arr, arr + N);

	int sum = 0;
	int idx = 0;
	int cut = arr[N - 1] + 1;
	while (sum < M) {
		cut--;
		if (arr[N - 1 - idx] == cut) {
			sum += idx;
			idx++;	
		}
		else {
			sum += idx;
		}
		printf("cut -- %d, sum -- %d\n", cut, sum);
	}

	printf("%d\n", cut);

	return 0;
}