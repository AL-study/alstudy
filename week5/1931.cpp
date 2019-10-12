
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#define ll long long int
using namespace std;

int n;
pair<int, int> dd[100000];

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> dd[i].second >> dd[i].first;
	}
	sort(dd, dd + n);
	int cnt = 0;
	int m = 0;
	for (int i = 0; i < n; i++) {
		if (dd[i].second >= m) {
			cnt++;
			m = dd[i].first;
		}
	}
	cout << cnt << '\n';

	return 0;
}