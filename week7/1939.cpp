
#include <iostream>
#include <queue>
#include <cstdio>
#include <cstring>

using namespace std;

int N,M,a,b,c,maxVal=-1,start,des;

int visited[100001];

typedef pair < int, int > pi;

vector < pi > vc[100001];
 
 
// 중량을 탐색할 BFS 함수
bool bfs(int weight){
	queue <int> que;    
    que.push(start);
    visited[start] = 1;
    
    while(!que.empty()){
    	
        int cur = que.front();
        
        que.pop();
        
        if(cur == des){
        	return true;
        }
        
        for(int i=0; i<vc[cur].size(); i++){
            int nVal = vc[cur][i].first;
            int next = vc[cur][i].second;
            
            if(visited[next] != 1 && weight <= nVal){
        	    visited[next] = 1;
            	que.push(next);
            
            }

        }
    }
    return false;
}
 
//중량을 검색할 이진탐색 함수
int bs(){
   
    int begin = 0,last = maxVal;
    while(begin<=last){
        
        int mid = (begin + last) / 2;
        
        memset(visited, 0, sizeof(visited));
        if(bfs(mid)){
            begin = mid+1;
        }else{
        	
            last = mid-1;
        }
    }
    return last;
}
 
int main(){
    scanf("%d %d", &N, &M);
    for(int i=0; i<M; i++){
        scanf("%d %d %d", &a, &b, &c);
        vc[a].push_back({c,b});
        vc[b].push_back({c,a});
  
        maxVal = max(maxVal,c);
    }
    
    scanf("%d %d", &start, &des);
    
    printf("%d\n" , bs());
    return 0;
}