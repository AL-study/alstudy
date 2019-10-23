#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<int> > q;

int main() {
	int T;
	scanf(" %d", &T);
	for (int t = 0; t < T; t++) {
		int n;
		scanf(" %d", &n);
		q.push(n);
	}

	int res = 0;
	while(q.size() != 1) {
		int num1 = q.top();
		q.pop();
		int num2 = q.top();
		q.pop();
		res += (num1 + num2);
		q.push(num1 + num2);
	}
	printf("%d\n", res);


	return 0;
}