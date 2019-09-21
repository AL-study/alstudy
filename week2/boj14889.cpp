#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, sscore = 0, lscore = 0;
vector<int> start, link;
vector< vector<int> > abt;

int score(vector<int> &s, vector<int> &l) {
  sscore = lscore = 0;
  for(int i=0; i<N/2; i++) {
    for(int j=i+1; j<N/2; j++) {
      sscore += abt[s[i]][s[j]] + abt[s[j]][s[i]];
      lscore += abt[l[i]][l[j]] + abt[l[j]][l[i]];
    }
  }
  return abs(sscore-lscore);
}

int main(){
  int i, j, temp;
  cin>>N;
  vector<int> bit, min, row;
  bit.assign(N/2, 0);
  for(i=0; i<N/2; i++) bit.push_back(1);
  for(i=0; i<N; i++) {
    row.clear();
    for(j=0; j<N; j++) {
      cin>>temp;
      row.push_back(temp);
    }
    abt.push_back(row);
  }
  do {
    start.clear();
    link.clear();
    for(i=0; i<N; i++) {
      if(bit[i]) start.push_back(i);
      else link.push_back(i);
    }
    min.push_back(score(start, link));
  }while(next_permutation(bit.begin(), bit.end()));
  cout<<*min_element(min.begin(), min.end())<<"\n";
  return 0;
}
