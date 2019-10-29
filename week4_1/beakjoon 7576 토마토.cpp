#include <iostream>
#include <queue>
using namespace std;
int n,m,arr[1001][1001],cnt,ans;
bool c[1001][1001];
enum{
	EMPTY=-1,
	RAW,
	RIPE
};
typedef struct _MOVE{
	int x,y;
}MOVE;
MOVE movedir[4]={{1,0},{-1,0},{0,1},{0,-1}};

void bfs(){
	queue<pair<int, pair<int,int> > > q;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(arr[i][j]==RIPE){
				q.push({0,{i,j}});
				c[i][j]=true;
			}
		}
	}
	while(!q.empty()){
		int x=q.front().second.first,y=q.front().second.second;
		int cnt=q.front().first;
		ans=max(ans,cnt);
		q.pop();
		for(int i=0;i<4;i++){
			int mx=x+movedir[i].x;
			int my=y+movedir[i].y;
			if(0<=mx && mx<n && 0<=my && my<m){
				if(!c[mx][my]&&arr[mx][my]==RAW){
					arr[mx][my]=RIPE;
					c[mx][my]=true;
					q.push({cnt+1,{mx,my}});
				}
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(arr[i][j]==RAW){
				ans=-1;
			}
		}
	}
	cout<<ans;
}

int main(){
	cin>>m>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>arr[i][j];
		}
	}
	bfs();
}
