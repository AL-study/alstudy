
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

stack<int> st;
vector<char> ans;
int a[100001];

int main() {
	int n;
	cin >> n;

	for(int i = 0;i<n;i++){
		cin >> a[i];
	}
	int tmp = 0;
	for(int j = 0;j<n;j++){
		st.push(j+1);
		ans.push_back('+');
		
		
		
		while( !st.empty() && a[tmp] == st.top()){
			st.pop();
			tmp++;
			ans.push_back('-');
		}
	}
    
    int size = ans.size();

	if(!st.empty()){
		cout << "NO" << "\n";
		
	}else if(st.empty()){
		for(int k = 0;k<size;k++){
			cout << ans[k] << "\n";
		}
	}
	return 0;
}