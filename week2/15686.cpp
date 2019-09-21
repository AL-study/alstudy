#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int N, M;
int arr[50][50];
vector<pair<int, int> > house;
vector<pair<int, int> > chicken;


int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) {
				house.push_back(pair<int, int>{ i, j });
			}
			else if (arr[i][j] == 2) {
				chicken.push_back(pair<int, int>{ i, j });
			}
		}
	}

	int arr[50] = { 0 };
	for (int i = 0; i < M; i++) arr[i] = 1;
	int min = 0x7FFFFFFF, dis, hsiz = house.size(), csiz = chicken.size();
	sort(arr, arr + csiz);
	do {
		int hdis = 0, mdis, distance;
		for (int i = 0; i < hsiz; i++) {
			mdis = 0x7FFFFFFF;
			for (int j = 0; j < csiz; j++) {
				if (!arr[j]) continue;
				distance = abs(house[i].first - chicken[j].first) + abs(house[i].second - chicken[j].second);
				if (mdis > distance) mdis = distance;
			}
			hdis += mdis;
		}
		if (min > hdis) min = hdis;

	} while (next_permutation(arr, arr + csiz));

	printf("%d\n", min);

	return 0;
}