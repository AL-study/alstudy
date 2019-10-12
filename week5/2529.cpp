#include <stdio.h>
#include <iostream>

using namespace std;

int N;
char op[10];
int amax[10];
bool bmax[10];
int amin[10];
bool bmin[10];
bool cmax;
bool cmin;

void fmax(int arr[], int i) {
	if (cmax) return;
	if (i == N + 1) {
		for (int k = 0; k < i; k++) amax[k] = arr[k];
		cmax = true;
		return;
	}

	for (int j = 9; j >= 0; j--) {
		if (bmax[j]) continue;

		if (i == 0) {
			arr[i] = j;
			bmax[j] = true;
			fmax(arr, i + 1);
			bmax[j] = false;
		}

		else {
			arr[i] = j;
			if (op[i - 1] == '<') {
				if (arr[i - 1] < arr[i]) {
					bmax[j] = true;
					fmax(arr, i + 1);
					bmax[j] = false;
				}
			}
			else {
				if (arr[i - 1] > arr[i]) {
					bmax[j] = true;
					fmax(arr, i + 1);
					bmax[j] = false;
				}
			}
		}
	}
}

void fmin(int arr[], int i) {
	if (cmin) return;
	if (i == N + 1) {
		for (int k = 0; k < i; k++) amin[k] = arr[k];
		cmin = true;
		return;
	}

	for (int j = 0; j < 10; j++) {
		if (bmin[j]) continue;

		if (i == 0) {
			arr[i] = j;
			bmin[j] = true;
			fmin(arr, i + 1);
			bmin[j] = false;
		}

		else {
			arr[i] = j;
			if (op[i - 1] == '<') {
				if (arr[i - 1] < arr[i]) {
					bmin[j] = true;
					fmin(arr, i + 1);
					bmin[j] = false;
				}
			}
			else {
				if (arr[i - 1] > arr[i]) {
					bmin[j] = true;
					fmin(arr, i + 1);
					bmin[j] = false;
				}
			}
		}
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> op[i];
	}

	int arr[10] = { 0 };
	fmax(arr, 0);
	fmin(arr, 0);

	for (int i = 0; i <= N; i++) printf("%d", amax[i]);
	printf("\n");
	for (int i = 0; i <= N; i++) printf("%d", amin[i]);
	printf("\n");

	return 0;
}