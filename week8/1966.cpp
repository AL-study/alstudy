
#include <queue>
#include <cstdio>
#include <cstring>

using namespace std;

int t;

int main() {

	scanf("%d", &t);	
	
	while(t--){


		queue<pair<int,int>> q;
		priority_queue<int> pq;
		
		int n,m;
		int num;
		//6 0
		scanf("%d %d", &n, &m);
		
		//pq = (5,0)
		for(int i = 0;i<n;i++){
			scanf("%d",&num);
			q.push(make_pair(num,i));
			pq.push(num);	
			
		}

		int cnt = 0;
		
		while(!pq.empty()){
			
			if(q.front().first == pq.top()){
				cnt++;
				if(q.front().second == m)break;
				pq.pop();
				
			}else{
				q.push(make_pair(q.front().first,q.front().second));
				
			}
			
			q.pop();
			
			
		}
		
		printf("%d\n", cnt);
		
		
	}
	return 0;
}
