#include <stdio.h>
#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int main() {
	int tc;
	cin >> tc;
	for (int t = 0; t < tc; t++) {
		char p[400002];
		int n;
		cin >> p;
		cin >> n;
		getchar();
		char a = 'A';
		deque<int> q;
		while ((a = getchar()) != '\n') {
			int sum = 0, num = a - '0';
			if (num > 0 && num <= 9) {
				sum += num;
				a = getchar();
				num = a - '0';
				if (num >= 0 && num <= 9) {
					sum = (sum * 10) + num;
					a = getchar();
					num = a - '0';
					if (num == 0) {
						sum *= 10;
					}
				}
			}
			if (!sum)continue;
			q.push_back(sum);
		}

		int idx = 0;
		bool check = true;
		bool rev = false;
		while (p[idx] != '\0') {
			char a = p[idx];
			if (a == 'R') {
				if (rev) rev = false;
				else rev = true;
			}
			else {
				if (q.empty()) {
					check = false;
					break;
				}
				if (rev) q.pop_back();
				else q.pop_front();
			}
			idx++;
		}

		if (check) {
			printf("[");
			if (q.empty()) printf("]\n");
			else {
				int siz = q.size();
				if (rev) {
					for (int i = 0; i < siz - 1; i++) {
						printf("%d,", q.back());
						q.pop_back();
					}
				}
				else {
					for (int i = 0; i < siz - 1; i++) {
						printf("%d,", q.front());
						q.pop_front();
					}
				}
				printf("%d]\n", q.front());
			}
		}
		else printf("error\n");
	}

	return 0;
}