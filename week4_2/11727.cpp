#include <stdio.h>
#include <iostream>

using namespace std;

int arr[1001] = { 0,1,3,5 };

int find(int x) {
	if (x == 0) return 0;
	if (arr[x]) return arr[x];
	return arr[x] = (find(x - 1) + (2 * find(x - 2))) % 10007;
}

int main() {
	int N;
	cin >> N;

	printf("%d\n", find(N));

	return 0;
}