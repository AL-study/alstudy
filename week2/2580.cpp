/*
#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int arr[9][9];
vector<int> v[9];
vector<int> h[9];

void siz() {
	printf("size\n");
	for (int i = 0; i < 9; i++) {
		printf("%d ", h[i].size());
	}
	printf("\n");
	for (int j = 0; j < 9; j++) {
		printf("%d ", v[j].size());
	}printf("\n");
}

void findone() {

	for (int i = 0; i < 9; i++) {
		if (h[i].size() == 1) {
			for (int j = 0; j < 9; j++) {
				if (arr[i][j] == 0) {
					arr[i][j] = h[i].front();
					h[i].pop_back();
				}
			}
		}
	}

	for (int j = 0; j < 9; j++) {
		if (v[j].size() == 1) {
			for (int i = 0; i < 9; i++) {
				if (arr[i][j] == 0) {
					arr[i][j] = v[j].front();
					v[j].pop_back();
				}
			}
		}
	}
}

void addv() {
	for (int i = 0; i < 9; i++) {
		int check[9] = { 0 };
		for (int j = 0; j < 9; j++) {
			if (arr[i][j]) check[arr[i][j] - 1] = 1;
		}
		for (int j = 0; j < 9; j++) {
			if (!check[j]) {
				h[i].push_back(j + 1);
			}
		}
	}

	for (int j = 0; j < 9; j++) {
		int check[9] = { 0 };
		for (int i = 0; i < 9; i++) {
			if (arr[i][j]) check[arr[i][j] - 1] = 1;
		}
		for (int i = 0; i < 9; i++) {
			if (!check[i]) {
				v[j].push_back(i + 1);
			}
		}
	}
}

int main() {

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> arr[i][j];
		}
	}
	addv();
	siz();
	findone();
	printf("\n\n");
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	siz();
	findone();
	printf("\n\n");
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}

	siz();

	return 0;
}
*/