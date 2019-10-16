#include <iostream>

using namespace std;
int main(){
  int A,B,V, day = 0;
  cin>>A>>B>>V;
  day = (V-B) / (A-B);
  if((V-B) % (A-B)) day++;
  cout<<day<<"\n";
  return 0;
}
