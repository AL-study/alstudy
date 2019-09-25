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
memset �Լ��� ����ϴ� ����
��ü�� memset�Լ��� Ư�� ������ �ִ� ���ӵ� �޸𸮿� ���� �����ϰ� ���� �� ����ϴµ� for������ �� ���� �ӵ��� ���ü��� �ִ�.
���⼭ ���ü��� �ִٶ�� ǥ���� ������ �����Ϸ� �׸��� ��ǻ�� ��Ű��ó�� ���� �ٸ��� �����̴�.
�ڼ��� ������ �Ʒ� �� �����ڷḦ ���� Quora���� ����� �ڵ�� ���Ѱ� �����ְ� Stack Overflow���� ������ ������� �����ִ�.
https://www.quora.com/What-makes-memset-so-fast
https://stackoverflow.com/questions/7367677/is-memset-more-efficient-than-for-loop-in-c
CC++
	
*/
