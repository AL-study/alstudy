#include <iostream>

using namespace std;

int main() {
  int N, temp;
  int price[10001][3];
  cin>>N;
  for(int i=1; i<=N; i++) {
    for(int j=0; j<3; j++) {
      cin>>temp;
      price[i][j] = temp;
    }
  }
  for(int i=2; i<=N; i++) {
    price[i][0] = min(price[i-1][1]+price[i][0], price[i-1][2]+price[i][0]);
    price[i][1] = min(price[i-1][0]+price[i][1], price[i-1][2]+price[i][1]);
    price[i][2] = min(price[i-1][0]+price[i][2], price[i-1][1]+price[i][2]);
  }
  cout<<min(min(price[N][0], price[N][1]), price[N][2])<<"\n";
  return 0;
}
