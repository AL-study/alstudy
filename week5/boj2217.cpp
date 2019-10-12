#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(int &rope1, int &rope2) {
  if(rope1 > rope2) return true;
  else return false;
}
int main(){
  int N, maxWeight = 0;
  cin>>N;
  int rope[N];
  for(int i=0; i<N; i++) {
    cin>>rope[i];
  }
  sort(rope, rope+N, cmp);
  for(int i=0; i<N; i++) {
    int temp = rope[i] * (i+1);
    if(temp > maxWeight) maxWeight = temp;
  }
  cout<<maxWeight<<"\n";
  return 0;
}
