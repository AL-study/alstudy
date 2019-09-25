
#include <iostream>
#include <queue>

using namespace std;

int check[200001];
int dist[200001];
queue<int> q;

int main() {
	int n,k;
	
	cin >> n >> k;
	
	check[n] = 1;
	dist[n] = 0;
	q.push(n);
	
	while(!q.empty()){
		int node = q.front();
		q.pop();
		if( (node-1) >= 0 && check[node-1]== 0){
			q.push(node-1);
			check[node-1] = 1;
			dist[node-1] = dist[node] +1;
		}
		
		if((node+1) < 200000 && check[node+1]== 0){
			q.push(node+1);
			check[node+1] = 1;
			dist[node+1] = dist[node] +1;
		}
		
		if((node*2) < 200000 && check[node*2]== 0){
			q.push(node*2);
			check[node*2] = 1;
			dist[node*2] = dist[node] +1;
		}
	}
	
	cout << dist[k] << endl;
	
	return 0;
}