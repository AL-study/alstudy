#include <iostream>
#include <queue>

using namespace std;

int n,m;
string arr[101];
int ans[101][101];
int move_x[4]={1,-1,0,0};
int move_y[4]={0,0,1,-1};

queue <pair <int,int> > q;
void bfs(int x,int y){
	arr[x][y]='9';
	q.push({x,y});
	ans[x][y] = 1;
	while(!q.empty()){
		int xx=q.front().first;
		int yy=q.front().second;
		q.pop();
		if(xx==n-1&&yy==m-1){
			cout<<ans[xx][yy];
			return;
		}
		for(int i=0;i<4;i++){
			int mx=xx+move_x[i];
			int my=yy+move_y[i];
			if(0<=mx && mx<=n-1 && 0<=my && my<=m-1){
				if(arr[mx][my]=='1'){
					arr[mx][my]='9';
					ans[mx][my] = ans[xx][yy]+1;
					q.push({mx,my});
				}
			}
		}
	}
}

int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	bfs(0,0);
}
