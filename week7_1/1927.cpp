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
		if (n != 0) {
			q.push(n);
		}
		else {
			if (q.empty()) printf("0\n");
			else {
				printf("%d\n", q.top());
				q.pop();
			}
		}
	}


	return 0;
}