
#include <queue>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

struct map{
	int x;
	int y;
};
int n,m;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
int a[101][101];
int ans;
int mincnt;
bool check[101][101];

int count(){
	int cnt = 0;
	for(int i = 1;i<n-1;i++){
		for(int j = 1;j<m-1;j++){
			if(a[i][j]==1){
				cnt++;
			}
		}
	}
	return cnt;
}

void solve(){
	queue<map> q;
	memset(check,false,sizeof(check));
	q.push({0,0});
	check[0][0] = true;
	
	while(!q.empty()){
		int x = q.front().x;
		int y = q.front().y;
		q.pop();
		//ans 되려면 
		
		for(int i = 0;i<4;i++){
			int nx = x+dx[i];
			int ny = y+dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
		
			
			if(a[nx][ny]==0 && !check[nx][ny]){
				q.push({nx,ny});
				check[nx][ny] = true;
			}
			
			
		}
	}
	
	
	for(int i = 1;i<n-1;i++){
		for(int j = 1;j<m-1;j++){
			//큐에 bfs넢고 바깥공기 영역이 모두 체크됨
			//체크도니 영역에 인접해 있는 치즈없애기
			//다음(겉테두리!!) 1인 상태에서 0으로 바꿈,
			
			//치즈 아닌부분 skip
			if(a[i][j] == 0) continue;
			
			//상하좡중 하나라도 밖이랑 닿아있으면 녹이기
			for(int k = 0;k<4;k++){
				int nx = i+dx[k];
				int ny = j+dy[k];
				
				if(check[nx][ny]){
					a[i][j] = 0;
					break;//진행못하게
				}
			}

		}
	}
}



int main() {

	//세로 가로
	scanf("%d %d", &n, &m);
	// 치즈없는칸0 치즈있는칸1
	
	for(int i = 0;i<n;i++){
		for(int j = 0;j<m;j++){
			scanf("%d",&a[i][j]);
			//cin >> a[i][j];
		}
	}

	while(true){
		
		int tmp = count();
		

		if(tmp == 0){
			break;
		}else{
			mincnt = tmp;
		}
		
		solve();
		ans++;
			
	}
	

	
	printf("%d\n%d\n", ans,mincnt);
	
	
	return 0;
}