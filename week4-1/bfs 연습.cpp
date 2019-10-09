#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> a[8];
int v[8];
queue <int> q;


void bfs(int start){
	q.push(start);
	v[start]=true;
	while(!q.empty()){
		int x=q.front();
		q.pop();
		cout<<x;
		for(int i=0;i<a[x].size();i++){
			int y=a[x][i];
			if(!v[y]){
				v[y]=true;
				q.push(y);
			}
		}
		
	}
}

int main(){
	
	a[1].push_back(2);
	a[2].push_back(1);
	
	a[1].push_back(3);
	a[3].push_back(1);
	
	a[2].push_back(3);
	a[3].push_back(2);
	
	a[2].push_back(4);
	a[4].push_back(2);
	
	a[2].push_back(5);
	a[5].push_back(2);
	
	a[4].push_back(5);
	a[5].push_back(4);
	
	a[3].push_back(6);
	a[6].push_back(3);
	
	a[3].push_back(7);
	a[7].push_back(3);
	
	a[6].push_back(7);
	a[7].push_back(6);
	
	
	bfs(1);
}
