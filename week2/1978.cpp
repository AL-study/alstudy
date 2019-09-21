
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int prime (int n){
	if(n < 2){
		return 0;
	}
	for(int i = 2;2*i<=n;i++){
		if(n%i == 0){
			return 0;
		}
	}
	return 1;
}
int main() {
	// your code goes here
	int n,num;
	cin >> n;
	int ans = 0;
	while(n--){
		cin >> num;
 
		ans += prime(num);
	}
 
	cout << ans << endl;
	return 0;
}