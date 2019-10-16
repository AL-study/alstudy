#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int m,n,k;
int v[101][101];
int arr[101][101];
int dirx[4]={1,-1,0,0};
int diry[4]={0,0,1,-1};
int cnt;
vector<int> result;

void dfs(int start_y,int start_x){
	v[start_y][start_x]=1;
	cnt++;

	for(int i=0;i<4;i++){
		int next_y=start_y+diry[i];
		int next_x=start_x+dirx[i];
		if(0<=next_x && next_x<n && 0<=next_y && next_y<m){
			if(v[next_y][next_x]==0&&arr[next_y][next_x]==0){
				dfs(next_y,next_x);
			}
		}
	}
	
}

int main(){

	cin>>m>>n>>k;
	
	for(int i=0;i<k;i++){
		int x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;
		
		for(int j=y1;j<y2;j++){
			for(int l=x1;l<x2;l++){
				arr[j][l]=1;
			}
		}
	}


	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(arr[i][j]==0&&v[i][j]==0){
				cnt=0;
				dfs(i,j);
				result.push_back(cnt);
			}
		}
	} 
	
	cout<<result.size()<<"\n";
	sort(result.begin(),result.end());
	for(int i=0;i<result.size();i++){
		cout<<result[i]<<" ";
	}
	

}
