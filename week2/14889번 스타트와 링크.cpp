#include <iostream>
#include <vector>
using namespace std;
int board[21][21];
int N;
int Min = 123123123;
vector<int> startTeam;
vector<int> linkTeam;
vector<int> pairInfo;
vector<int> target;
int Sum = 0;
void getAllPairSum(int idx) {
	if (pairInfo.size() > 2) {
		return;
	}
	if (idx == (N / 2)) {
		if (pairInfo.size() == 2) {
			Sum += board[pairInfo[0]][pairInfo[1]] + board[pairInfo[1]][pairInfo[0]];
		}
	}
	else {
		pairInfo.push_back(target[idx]);
		getAllPairSum(idx + 1);
		pairInfo.pop_back();
		getAllPairSum(idx + 1);
	}
}
void divideTeams(int number) {
	if (startTeam.size() > (N / 2)) {
		return;
	}
	if (number == N + 1) {
		int startTeamSize = startTeam.size();
		if ( startTeamSize == (N / 2)) {
			int idx = 0;
			for (int i = 1; i <= N; i++) {
				if (i != startTeam[idx]) {
					linkTeam.push_back(i);
				}
				else {
					idx++;
					if (idx == (N / 2)) {
						i++;
						while ( i<= N) {
							linkTeam.push_back(i);
							i++;
						}
						break;
					}
				}
			}
			Sum = 0;
			target = startTeam;
			getAllPairSum(0);
			int startSum = Sum;
			target.clear();
			pairInfo.clear();
			Sum = 0;
			target = linkTeam;
			getAllPairSum(0);
			pairInfo.clear();
			int linkSum = Sum;
			int diff = abs(startSum - linkSum);
			if (Min > diff) {
				Min = diff;
			}

			linkTeam.clear(); 
		}
	}
	else {
		startTeam.push_back(number);
		divideTeams(number + 1);
		startTeam.pop_back();
		divideTeams(number + 1);
	}
}
int main() {
	scanf("%d", &N);
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &board[i][j]);
		}
	}
	divideTeams(1);
	printf("%d", Min);
	return 0;
}