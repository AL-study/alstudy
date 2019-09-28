#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, temp;
  vector<int> score, ret;
  score.push_back(0);
  ret.push_back(0);
  
  cin>>N;
  for(int i=0; i<N; i++) {
    cin>>temp;
    score.push_back(temp);
  }
  
  ret.push_back(score[1]);
  ret.push_back(score[1]+score[2]);
  ret.push_back(max(score[1]+score[3], score[2]+score[3]));
  
  for(int i=4; i<=N; i++) {
    ret.push_back(max(ret[i-2]+score[i], ret[i-3]+score[i-1]+score[i]));
  }
  cout<<ret[N]<<"\n";
  return 0;
}
