#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

enum{
	AIR=0,
	CHEESE,
	PREAIR
};
int l,c,arr[100][100],lastcnt,result;
bool check[100][100];
typedef struct{
	int x,y;
}Dir;
Dir movedir[4]={{1,0},{-1,0},{0,1},{0,-1}};

bool possible(){
	int cnt=0;
	for(int i=0;i<l;i++){
		for(int j=0;j<c;j++){
			if(arr[i][j]==CHEESE){
				cnt++;
			}
		}
	}
	if(cnt){
		lastcnt=cnt;
	}
	if(cnt==0){
		return true;
	}else{
		return false;
	}
}

void makeair(){
	for(int i=0;i<l;i++){
		for(int j=0;j<c;j++){
			if(arr[i][j]==PREAIR){
				arr[i][j]=AIR;
			}
		}
	}
}

void bfs(){
	// 방문배열 초기화 
	memset(check,0,sizeof(check));
	queue< pair<int, int> > q;
	q.push({0,0});
	while(!q.empty()){
		int xx=q.front().first, yy=q.front().second;
		q.pop();
		for(int i=0;i<4;i++){
			int mx=xx+movedir[i].x;
			int my=yy+movedir[i].y;
			if(0<=mx&&mx<l&&0<=my&&my<c&&!check[mx][my]){
				if(arr[xx][yy]==AIR&&arr[mx][my]==CHEESE){
					check[mx][my]=true;
					arr[mx][my]=PREAIR;
				}	
				if(arr[mx][my]==AIR){
					check[mx][my]=true;
					q.push({mx,my});					
				}
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
	cin>>l>>c;
	for(int i=0;i<l;i++){
		for(int j=0;j<c;j++){
			cin>>arr[i][j];
		}
	}
	while(1){
		if(possible()){
			break;
		}
		bfs();
		makeair();
		result++;
	}	
	cout << result << "\n";
    cout << lastcnt << "\n";
    return 0;
	
}
