#include <iostream>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
  if(max(a,b) % min(a,b) != 0) gcd(min(a,b), max(a,b) % min(a,b));
  else return min(a,b);
}

int lcm(int a, int b) {
  return a * b / gcd(a,b);
}

int main() {
  int a,b;
  cin>>a>>b;
  cout<<gcd(a,b)<<"\n"<<lcm(a,b)<<"\n";
  return 0;
}
