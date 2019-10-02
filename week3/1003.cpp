
#include <iostream>
#include <vector>
using namespace std;

pair<int,int> d[42];
	
int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int T;
	cin >> T;	
	
	d[0] = {1,0};//d[0] = (1,0)
	d[1] = {0,1};
	for(int i = 2;i<=40;i++){
			d[i].first = d[i-1].first + d[i-2].first;
			d[i].second = d[i-1].second + d[i-2].second;
	}
	
	
	int num;
	while(T--){
		
		cin >> num;
		
		cout << d[num].first << " " << d[num].second << endl;
	}
	return 0;
}