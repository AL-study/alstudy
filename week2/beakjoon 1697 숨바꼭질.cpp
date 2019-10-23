#include <iostream>
#include <queue>
#include <vector>

using namespace std;	
int n,k,check[200001];
queue<int> q;
void bfs(int start){
	q.push(start);
	check[start]=0;
	while(!q.empty()){
		int x=q.front();
		q.pop();
		if(x==k){
			cout<<check[k];
			return;
		}
		if(0<=x-1 && !check[x-1]){
			q.push(x-1);
			check[x-1]=check[x]+1;
		}
		if(x+1 <= 200000 && !check[x+1]){
			q.push(x+1);
			check[x+1]=check[x]+1;
		}
		if(x*2 <=200000 && !check[x*2]){
			q.push(x*2);
			check[x*2]=check[x]+1;
		}
	}
} 
int main(){	
	cin>>n>>k;
	bfs(n);
}
