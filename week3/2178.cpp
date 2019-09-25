

#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

int a[101][101];
int check[101][101];
int dist[101][101];
queue<pair<int,int>> q;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int n,m;

void bfs(int x,int y){
	
	check[x][y] = 1;
	q.push(make_pair(x,y));
	dist[x][y]= 1;
	
	while(!q.empty()){
		
		x = q.front().first;
		y = q.front().second;
		q.pop();
		
		for(int i = 0;i<4;i++){
			int nx = x+dx[i];
			int ny = y+dy[i];
			if(0<= nx && nx < n && 0 <= ny && ny < m){
				if(a[nx][ny] == 1 && check[nx][ny] == 0){
					q.push(make_pair(nx,ny));
					check[nx][ny] = 1;
					dist[nx][ny] = dist[x][y]+1;
				}
				
			}
		}
	}
}
int main() {
	// your code goes here
	
	scanf("%d %d", &n,&m);
	
	for(int i = 0;i<n;i++){
		for(int j = 0;j<m;j++){
			scanf("%1d", &a[i][j]);
		}
	}
	
	for(int i = 0;i<n;i++){
		for(int j = 0;j<m;j++){
			if(a[i][j] == 1 && check[i][j] == 0){
				bfs(i,j);
			}
		}
	}
	
	
	printf("%d",dist[n-1][m-1]);
	return 0;
}
