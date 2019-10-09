#include<iostream>
#include<algorithm>
using namespace std;
int d[10001];
int podo[10001];
int solve(int n) {
	// �Ǹ����� �����ָ� ������ �� ��ĭ�� �����ָ� ���Ű��, �ȸ��� ��� 
	// 1. ���Ű�� = podo[i] + podo[i-1] + d[i-3];
	// 2. �ȸ��� ��� = podo[i] + d[i-2]
	// �� ������ �����ָ� ������ �ʾ�����
	// d[n] = d[n-1]
	d[1] = podo[1];
	d[2] = podo[1] + podo[2];
	for (int i = 3; i <= n; i++) {
		int tmp1 = podo[i] + podo[i - 1] + d[i - 3];
		int tmp2 = podo[i] + d[i - 2];
		d[i] = max(tmp1, tmp2);
		d[i] = max(d[i], d[i - 1]);
	}
	return d[n];
}
int main() {
	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &podo[i]);
	}
	printf("%d", solve(N));
	return 0;
}