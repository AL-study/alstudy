/*
#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	int arr[1001];
	int cnt[1001] = { 0 };
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int max = 0;
	for (int i = 0; i < n; i++) {
		int temp = 0;
		for (int j = 0; j <= i; j++) {
			if (temp <= arr[j]) {
				cnt[i]++;
				temp = arr[j];
			}
		}
		if (cnt[i] > max) max = cnt[i];
	}

	for (int i = 0; i < n; i++)printf("%d ", cnt[i]);
	printf("\n");

	printf("%d\n", max);

	return 0;
}
*/