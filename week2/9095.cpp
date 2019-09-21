#include <stdio.h>
#include <iostream>

using namespace std;

int arr[11];

int find(int x) {
	if (arr[x]) return arr[x];

	if (x == 1)return 1;
	else if (x == 2) return 2;
	else if (x == 3)return 4;

	return find(x - 3) + find(x - 2) + find(x - 1);
}

int main() {
	int tc;
	cin >> tc;
	for (int t = 0; t < tc; t++) {
		int n;
		cin >> n;
		printf("%d\n", find(n));
	}

	return 0;
}
