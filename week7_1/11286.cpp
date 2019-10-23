#include <stdio.h>
#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

class Num {
public:
	int x;
	Num(int x) {
		this->x = x;
	}

	bool operator <(const Num &n) const {
		if (abs(this->x) == abs(n.x)) return (this->x > n.x);
		return (abs(this->x) > abs(n.x));
	}
};

priority_queue<Num> q;

int main() {
	int T;
	scanf(" %d", &T);
	for (int t = 0; t < T; t++) {
		int n;
		scanf(" %d", &n);
		if (n != 0) {
			q.push(Num(n));
		}
		else {
			if (q.empty()) printf("0\n");
			else {
				printf("%d\n", q.top().x);
				q.pop();
			}
		}
	}


	return 0;
}