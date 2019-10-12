
#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

int a[1001][1001];
int dist[1001][1001];


int dx[] = {-1,1,0,0};
int dy[] = {0,0,1,-1};

int n,m;


int main() {
    // your code goes here
    queue<pair<int,int>> q;

    scanf("%d %d", &m , &n);
    
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            
            scanf("%d", &a[i][j]);
            dist[i][j] = -1;
            if(a[i][j] == 1){//지금 위치에서 갈 수 있는 것 큐에 다 넣음
                dist[i][j] = 0;
                q.push(make_pair(i,j));
            }
        }
    }
    
    

    while(!q.empty()){
        
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        
        
        for(int k = 0;k<4;k++){
            int nx = x+dx[k];
            int ny = y+dy[k];

        if(0<= nx && nx < n && 0 <= ny && ny < m){          
            if(a[nx][ny] == 0 && dist[nx][ny] == -1){
                q.push(make_pair(nx,ny));
                dist[nx][ny] = dist[x][y]+1;
                
            }
        }
                
            
        }
    }
    
    
    int ans = 0;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(dist[i][j] > ans){
                ans = dist[i][j];       
            }

        }
    }
    
    
     for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(dist[i][j] == -1 && a[i][j] == 0){
                ans =-1;       
            }

        }
    }
    
    printf("%d\n",ans);
    
    return 0;