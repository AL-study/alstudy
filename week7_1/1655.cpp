#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<int> > maxq;
priority_queue<int, vector<int>, less<int> > minq;

int main() {
	int N;
	cin >> N;
	int maxsize = 0, minsize = 0;
	for (int i = 0; i < N; i++) {
		int n;
		scanf(" %d", &n);
		if (minsize == 0) {
			minq.push(n);
			minsize++;
		}
		else if (minsize > maxsize) {
			if (minq.top() > n) {
				maxq.push(minq.top());
				minq.pop();
				minq.push(n);
				maxsize++;
			}
			else {
				maxq.push(n);
				maxsize++;
			}
		}
		else if (minsize == maxsize) {
			if (maxq.top() < n) {
				minq.push(maxq.top());
				maxq.pop();
				maxq.push(n);
				minsize++;
			}
			else {
				minq.push(n);
				minsize++;
			}
		}

		printf("%d\n", minq.top());
	}

	return 0;
}