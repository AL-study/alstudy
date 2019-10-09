#include <stdio.h>
#include <iostream>

using namespace std;

int main() {

	int n;
	int arr[1000001] = { 0 };
	cin >> n;
	arr[2] = 1;

	for (int i = 2; i <= n; i++) {
		if (i % 3 == 0) {
			if ((arr[i / 3] + 1) < arr[i - 1] + 1) arr[i] = arr[i / 3] + 1;
			else arr[i] = arr[i - 1] + 1;
		}
		else if (i % 2 == 0) {
			if ((arr[i / 2] + 1) < arr[i - 1] + 1) arr[i] = arr[i / 2] + 1;
			else arr[i] = arr[i - 1] + 1;
		}
		else {
			arr[i] = arr[i - 1] + 1;
		}
	}

	printf("%d\n", arr[n]);

	return 0;
}