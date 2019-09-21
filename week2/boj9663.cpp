#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int N, ans = 0;
int *put;

bool promising(int curr) {
  for(int i=0; i<curr; i++) {
    if(put[i] == put[curr]) return false; //직선인지
    else if(abs(put[i]-put[curr]) == abs(i-curr)) return false; //대각선인지 확인
  }
  return true;
}

void search(int curr) {
  if(curr == N-1)  { //N-2행까지 유효했다면 N-1행에서 퀸을 배치하는 경우는 1가지로 특정됨.
    ans++;
    return;
  }
  else {
    for(int i=0; i<N; i++) {
      put[curr+1] = i;
      if(promising(curr+1)) search(curr+1); //다음 행이 유효한지 탐색.
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  int i, j;
  cin>>N;
  put = new int[N];
  search(-1);
  printf("%d\n", ans);
  return 0;
}
