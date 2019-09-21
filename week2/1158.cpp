#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	int N,M;
	queue<int> q;
	cin >> N >> M;
	vector<int> v(N);
	
	for(int i = 1;i<=N;i++){
		q.push(i);
	}
	
	for(int k = 0;k<N;k++){
		for(int j = 0;j<M-1;j++){
			q.push(q.front());
			q.pop();
		}
		v[k] = q.front();
		q.pop();
	}
	
	cout << "<";
	for(int i = 0;i<v.size();i++){
		cout << v[i];
		
		if(i == N-1){
			break;
		}else{
			cout << ", ";
		}
	}
	cout << ">" << "\n";
	return 0;
}