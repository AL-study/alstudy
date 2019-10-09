#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int n,m,ans,arr[101][101];
bool visited[101];
queue<int> q;

void bfs(int idx){
	q.push(idx);
	visited[idx]=1;
	while(!q.empty()){
		idx=q.front();
		q.pop();
		//cout<<idx<<" ";
		ans++;
		
		for(int i=1;i<=n;i++){
			if(arr[idx][i]&&!visited[i]){
				visited[i]=1;
				q.push(i);
			}
		}
	}
}

int main(){
	
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		arr[a][b]=1;
		arr[b][a]=1;
	}
	
	visited[1]=true;
	bfs(1);	
	cout<<ans-1;
	
}


