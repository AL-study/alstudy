#include <iostream>
#include <queue>
using namespace std;
int n,m,h,arr[101][101][101],cnt,ans;
bool c[101][101][101];
enum{
	EMPTY=-1,
	RAW,
	RIPE
};
typedef struct _MOVE{
	int x,y,z;
}MOVE;
MOVE movedir[6]={{1,0,0},{-1,0,0},{0,1,0},{0,-1,0},{0,0,1},{0,0,-1}};

void bfs(){
	queue<pair<pair<int,int>, pair<int,int> > > q;
	for(int t=0;t<h;t++){
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(arr[i][j][t]==RIPE){
					q.push({{0,t},{i,j}});
					c[i][j][t]=true;
				}
			}
		}
	}
	
	while(!q.empty()){
		int x=q.front().second.first,y=q.front().second.second,z=q.front().first.second;
		int cnt=q.front().first.first;
		ans=max(ans,cnt);
		q.pop();
		for(int i=0;i<6;i++){
			int mx=x+movedir[i].x;
			int my=y+movedir[i].y;
			int mz=z+movedir[i].z;
			if(0<=mx && mx<n && 0<=my && my<m &&0<=mz &&mz<h){
				if(!c[mx][my][mz]&&arr[mx][my][mz]==RAW){
					arr[mx][my][mz]=RIPE;
					c[mx][my][mz]=true;
					q.push({{cnt+1,mz},{mx,my}});
				}
			}
		}
	}
	for(int t=0;t<h;t++){
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(arr[i][j][t]==RAW){
					ans=-1;
				}
			}
		}
	}
	cout<<ans;
}

int main(){
	cin>>m>>n>>h;
	for(int t=0;t<h;t++){
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin>>arr[i][j][t];
			}
		}	
	}
	
	bfs();
}
