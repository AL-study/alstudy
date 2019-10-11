#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> &p1, pair<int, int> &p2) {
  if(p1.second < p2.second) return true;
  else if(p1.second > p2.second) return false;
  else if(p1.first < p2.first) return true;
  else return false;
}

int main(){
  vector<pair<int, int> > meetingTime;
  int N, p1, p2, cnt = 0, endTime = 0;
  cin>>N;
  for(int i=0; i<N; i++) {
    cin>>p1>>p2;
    meetingTime.push_back(make_pair(p1,p2));
  }
  sort(meetingTime.begin(), meetingTime.end(), cmp);
  for(int i=0; i<N; i++) {
    if(endTime <= meetingTime[i].first) {
      endTime = meetingTime[i].second;
      cnt++;
    }
  }
  cout<<cnt<<"\n";
  return 0;
}
