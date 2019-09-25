
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> a[100];
int check[100];
int n,m;
int cnt;
void dfs(int v){
	check[v] = 1;
	for(int i = 0;i<a[v].size();i++){
		int y = a[v][i];
		if(check[y] == 0){
			dfs(y);
			cnt++;
		}
	}
}
int main() {
	scanf("%d", &n);
	scanf("%d", &m);
	
	int x,y;
	
	for(int i = 0;i<m;i++){
		scanf("%d %d", &x,&y);
		a[x].push_back(y);
		a[y].push_back(x);
		
	}
	
	cnt = 0;
	
	dfs(1);
	printf("%d\n",cnt);
	return 0;
}