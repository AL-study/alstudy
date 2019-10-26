#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <string>

using namespace std;

bool cmp(string &str1, string &str2){
  return (str1+str2) > (str2+str1);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  bool chk = false;
  int K, N, high = 0;
  cin>>K>>N;
  string number[K];
  for(int i=0; i<K; i++) {
    cin>>number[i];
    if(high < atoi(number[i].c_str())) high = atoi(number[i].c_str());
  }
  sort(number, number+K, cmp);
  for(int i=0; i<K; i++) {
    cout<<number[i];
    if(atoi(number[i].c_str()) == high && !chk) {
      chk = true;
      for(int j=0; j< N-K; j++) {
        cout<<number[i];
      }
    }
  }
  cout<<"\n";
  return 0;
}
