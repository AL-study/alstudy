#include <iostream>
#include <queue>
#include <cstring>
#include <climits>
using namespace std;
int n,m,ans=INT_MAX;
string arr[1001];
bool c[1001][1001][2];
typedef struct _Move{
	int x,y;
}Move;
Move movedir[4]={{1,0},{-1,0},{0,1},{0,-1}}; 
void bfs(){
	queue<pair<int,pair<int, int> > > q;
	queue<int> cq;
	q.push(make_pair(1,make_pair(0,0)));
	c[0][0][1]=true;
	cq.push(1);
	while(!q.empty()){
		int x=q.front().second.first,y=q.front().second.second;
		int crush=q.front().first;
		int cnt=cq.front();
		if(x==n-1&&y==m-1){
			ans=min(cnt,ans);	
		}
		q.pop();
		cq.pop();
		for(int i=0;i<4;i++){
			int mx=movedir[i].x+x;
			int my=movedir[i].y+y;
			if(0<=mx&&mx<n&&0<=my&&my<m){
				if(arr[mx][my]=='1'&&crush==1){
					q.push(make_pair(0,make_pair(mx,my)));
					c[mx][my][0]=true;
					cq.push(cnt+1);
				}else if(arr[mx][my]=='0'&&!c[mx][my][crush]){
					q.push(make_pair(crush,make_pair(mx,my)));
					c[mx][my][crush]=true;
					cq.push(cnt+1);
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
	bfs();
	if(ans==INT_MAX){
		cout<<"-1";
	}else{
		cout<<ans;
	}
}
