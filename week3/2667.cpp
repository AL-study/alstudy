
#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

int a[25][25];
int check[25][25];
int cnt;
queue<pair<int,int>> q;

int f[25*25];

int dx[] = {-1,1,0,0};
int dy[] = {0,0,1,-1};

int n;

void bfs(int x,int y,int cnt){
	check[x][y] = cnt;
	q.push(make_pair(x,y));
	
	while(!q.empty()){
		
		x = q.front().first;
		y = q.front().second;
		q.pop();
		
		for(int i = 0;i<4;i++){
			int nx = x+dx[i];
			int ny = y+dy[i];
			if(0<= nx && nx < n && 0 <= ny && ny < n){
				if(a[nx][ny] == 1 && check[nx][ny] == 0){
					q.push(make_pair(nx,ny));
					check[nx][ny] = cnt;
				}
				
			}
		}
	}
}
int main() {
	// your code goes here
	
	scanf("%d", &n);
	
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){
			scanf("%1d", &a[i][j]);
		}
	}
	cnt = 0;
	
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){
			if(a[i][j] == 1 && check[i][j] == 0){
				bfs(i,j,++cnt);
			}
		}
	}

	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){
			f[check[i][j]]+= 1;
		}
	}	
	
	sort(f+1, f+cnt+1);
	
	printf("%d\n",cnt);
	
	for(int i = 1;i<=cnt;i++){
		printf("%d\n",f[i]);
	}
	return 0;
}