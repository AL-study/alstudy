
#include <iostream>
#include <string>
using namespace std;

char stack[51];

int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	int T;
	
	cin >> T;
	while(T--){
		string s = "";
		int cnt = 0;
		cin >> s;
		
		for(int j = 0;j<s.size();j++){
			if(s[j] == '('){
				cnt +=1;
				
			}else if(s[j] == ')'){
				cnt -=1;
			}
			
			if(cnt < 0){
			 	cout << "NO" << "\n";
				break;
			}
		}
		
		if(cnt == 0){
			cout << "YES" << "\n";
		}else if(cnt >0){
			cout << "NO" << "\n";
		}
		
	}
	return 0;
}