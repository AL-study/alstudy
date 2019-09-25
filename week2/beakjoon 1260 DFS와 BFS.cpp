#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int n,m,start,arr[1001][1001];
bool visited[1001];
queue<int> q;

void dfs(int idx){
	cout<<idx<<" ";
	for(int i=1;i<=n;i++){
		if(arr[idx][i]&&!visited[i]){
			visited[i]=1;
			dfs(i);
		}
	}
}


void bfs(int idx){
	q.push(idx);
	visited[idx]=1;
	while(!q.empty()){
		idx=q.front();
		q.pop();
		cout<<idx<<" ";
		
		for(int i=1;i<=n;i++){
			if(arr[idx][i]&&!visited[i]){
				visited[i]=1;
				q.push(i);
			}
		}
	}
}

int main(){
	
	cin>>n>>m>>start;
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		arr[a][b]=1;
		arr[b][a]=1;
	}
	
	visited[start]=true;
	dfs(start);
	cout<<"\n";
	//[1]
	memset(visited,0,sizeof(visited));
	bfs(start);	
	
}


/*

[1]
memset 함수를 사용하는 이유
대체로 memset함수는 특정 범위에 있는 연속된 메모리에 값을 지정하고 싶을 때 사용하는데 for문보다 더 빠른 속도가 나올수가 있다.
여기서 나올수가 있다라고 표현한 이유는 컴파일러 그리고 컴퓨터 아키텍처에 따라서 다르기 때문이다.
자세한 내용은 아래 두 참고자료를 보면 Quora에는 어셈블리 코드로 비교한게 나와있고 Stack Overflow에는 관련한 내용들이 나와있다.
https://www.quora.com/What-makes-memset-so-fast
https://stackoverflow.com/questions/7367677/is-memset-more-efficient-than-for-loop-in-c
CC++
	
*/
