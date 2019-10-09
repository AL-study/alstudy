#include<iostream>
#include<algorithm>
using namespace std;
int arr[100001];
int N;
int getMaxSum(int start, int end) {
	if (start >= end) {
		return arr[start];
	}
	else {
		int mid = (start + end) / 2;

		int left = getMaxSum(start, mid);
		int right = getMaxSum(mid + 1, end);

		int Sum = 0;
		int leftSum = -1001;
		for (int i = mid; i >= start; i--) {
			Sum += arr[i];
			leftSum = max(Sum, leftSum);
		}
		Sum = 0;
		int rightSum = -1001;
		for (int i = mid + 1; i <= end; i++) {
			Sum += arr[i];
			rightSum = max(Sum, rightSum);
		}

		int res = max(max(left, right), (leftSum + rightSum));
		return res;
	}
}
int main() {

	scanf("%d", &N);

	for (int i = 0; i<N; i++) {
		scanf("%d", &arr[i]);
	}
	int res = getMaxSum(0, N - 1);
	printf("%d\n", res);
	return 0;
}