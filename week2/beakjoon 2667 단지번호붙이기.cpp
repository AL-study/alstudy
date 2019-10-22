#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int n;
string arr[25];
bool check[25][25];
vector<int> v;
queue<pair<int, int > > q;
int move_x[4]={1,-1,0,0};
int move_y[4]={0,0,1,-1};

void bfs(int start_x,int start_y){
	int cnt=1;
	q.push({start_x,start_y});
	check[start_x][start_y]=true;
	while(!q.empty()){
		int xx=q.front().first;
		int yy=q.front().second;
		q.pop();
		for(int i=0;i<4;i++){
			int mx=move_x[i]+xx;
			int my=move_y[i]+yy;
			if(0<=mx && mx<n && 0<=my && my<n){
				if(arr[mx][my]=='1'&&!check[mx][my]){ 
					check[mx][my]=true; 
					q.push({mx,my});
					cnt++;
				}
			}
		}
		
	}
	v.push_back(cnt);
}

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(!check[i][j]&&arr[i][j]=='1'){
				bfs(i,j);
			}
		}
	}
	sort(v.begin(),v.end());
	cout<<v.size()<<"\n";
	for(int i=0;i<v.size();i++){
		cout<<v[i]<<"\n";
	}
} 
