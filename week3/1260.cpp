
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#include <string.h>//memset

using namespace std;

int n,m,v;
int check[1001];
vector<int> a[1001];
queue<int> q;

void dfs(int x){
	check[x] = 1; //true
	printf("%d ",x);
	for(int i = 0;i<a[x].size();i++){
		int y = a[x][i];
		if(check[y] == 0){
			dfs(y);
		}
	}
}

void bfs(int x){
	
	check[x] = 1; //true
	q.push(x);
	while(!q.empty()){
		int node = q.front();
		q.pop();
		printf("%d ",node);
		for(int i = 0;i<a[node].size();i++){
			int y = a[node][i];
			if(check[y] == 0){
				q.push(y);
				check[y] = 1;
		}			
		}

	}
}
int main() {
	// your code goes here
	scanf("%d %d %d", &n, &m, &v);
	int x,j;
	for(int i = 0;i<m;i++){
		scanf("%d %d", &x, &j);
		a[x].push_back(j);
		a[j].push_back(x);
	}
	
	for(int i = 0;i<n;i++){
		sort(a[i].begin(),a[i].end());
	}
	
	dfs(v);
	printf("\n");
	memset(check,0,sizeof(check));
	bfs(v);
	printf("\n");
	return 0;
}
