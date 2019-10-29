# week4-2 DFS & BFS



### 2206 벽 부수고 이동하기 ★

- 벽을 한 번 부술 수 있을 때의 최단 거리를 구하는 문제

- 쉬워보이지만 부쉈을경우, 부수지 않았을 경우에 대해 방문처리를 다르게 해야하고, 이러한 발상을 하기 어려웠던 문제

  - 방문처리의 경우를 나누어 주지 않았을 경우 반례는 다음과 같다.
    4 7
    0100010
    0101010
    0101010
    0001010

- 벽을 부쉈을 경우와 부수지 않았을 경우를 나누어 방문배열을 저장해야 하기 때문에 **3차원**배열을 선언해야 한다.

- ```C++
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
  // 변수이름이 move일 경우 컴파일 에러
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
  	if(ans=INT_MAX){
  		cout<<"-1";
  	}else{
  		cout<<ans;
  	}
  }
  ```



### 7576. 토마토

- 익은 토마토의 주위에 있는 (4방향에 인접해있는) 익지 않은 토마토는 1일후에 모두 익은 토마토가 된다. 바이러스처럼 퍼져나가는 신기한 능력을 가진 익은 토마토로 (궁금해서 검색해봤지만 역시 실제로 그렇진않다) 전부 변하기 까지의 최소일 수를 구하는문제

- 익은 토마토, 익지 않은 토마토, 빈 공간 총 3가지의 상태가 배열로 주어진다. 여러상태를 처리하기 위해 enum을 활용했다. (물론 쓰지 않아도 지장없지만 가독성을 높여 이해하기 쉬운 코드로 만들어주자.)

- 배열을 받고 bfs를 통해 가지를 뻗어 나가는데 시작점은 여러 개 일 수 있다. 따라서 배열을 탐색해 익은(RIPE)상태의 토마토라면 큐에 전부다 넣고 bfs를 시작 하면 된다.

- 주의사항

  - exit(1)로 프로그램을 끝내면 런타임에러가 발생한다. exit를 사용하지 않도록 한다. if문을 통해 처리하자.

- ```c++
  #include <iostream>
  #include <queue>
  using namespace std;
  int n,m,arr[1001][1001],cnt,ans;
  bool c[1001][1001];
  enum{
  	EMPTY=-1,
  	RAW,
  	RIPE
  };
  typedef struct _MOVE{
  	int x,y;
  }MOVE;
  MOVE movedir[4]={{1,0},{-1,0},{0,1},{0,-1}};
  
  void bfs(){
  	queue<pair<int, pair<int,int> > > q;
  	for(int i=0;i<n;i++){
  		for(int j=0;j<m;j++){
  			if(arr[i][j]==RIPE){
  				q.push({0,{i,j}});
  				c[i][j]=true;
  			}
  		}
  	}
  	while(!q.empty()){
  		int x=q.front().second.first,y=q.front().second.second;
  		int cnt=q.front().first;
  		ans=max(ans,cnt);
  		q.pop();
  		for(int i=0;i<4;i++){
  			int mx=x+movedir[i].x;
  			int my=y+movedir[i].y;
  			if(0<=mx && mx<n && 0<=my && my<m){
  				if(!c[mx][my]&&arr[mx][my]==RAW){
  					arr[mx][my]=RIPE;
  					c[mx][my]=true;
  					q.push({cnt+1,{mx,my}});
  				}
  			}
  		}
  	}
  	for(int i=0;i<n;i++){
  		for(int j=0;j<m;j++){
  			if(arr[i][j]==RAW){
                  // exit(1); 주석해제시 런타임에러 발생
  				ans=-1;
  			}
  		}
  	}
  	cout<<ans;
  }
  int main(){
  	cin>>m>>n;
  	for(int i=0;i<n;i++){
  		for(int j=0;j<m;j++){
  			cin>>arr[i][j];
  		}
  	}
  	bfs();
  }
  ```

  

### 7569 토마토



### 9466 팀 프로젝트



### 2636. 치즈 ★

치즈의 가운데 부분이 비어있지않고 속이 꽉 찬 완전한 치즈였다면 어렵지 않게 풀었을 것이다. 그러나 속이 빈 치즈 즉, 1로 둘러싸인 배열 안에 0이 존재할 경우 치즈 안쪽도 녹아 없어져버린다. 이 부분을 어떻게 해결해야할지 방법이 떠오르지 않아서 참고출처의 코드를 참고 했다. 알고리즘은 다음과 같다.

- 치즈가 모두 녹았는지 확인하고 모두 녹았다면 true를 반환하고 해당 개수를 출력 (전부다 녹기전 마지막 순간의 치즈 수)

- 모두 녹지 않은 경우, BFS를 통해 공기가 존재하는 칸에 공기표시

- BFS를 한 번 더 돌려 치즈가 녹을 지점을 표시. 이때 PREAIR(녹을 지점)로 상태 변경

- PREAIR상태의 치즈가 녹아야 하므로 PREAIR를 AIR로 상태 변경

- 상태를 알기 쉽게 enum을 이용하여 변경

- bfs를 2번 돌려야 하는 문제 (출처의 방식대로 코딩한다면)

  - 처음 공기는 0이고 1안에 있는 0을 탐색하지 않기 위함

- ```C++
  #include <iostream>
  #include <queue>
  #include <cstring>
  using namespace std;
  
  typedef struct
  {
      int y, x;
  }Dir;
  
  Dir moveDir[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
  
  enum{CHEESE=1, PREAIR, AIR};
  int N, M;
  int lastCnt;
  int arr[100][100];
  bool visited[100][100];
  bool allClear(void)
  {
      int cnt = 0;
      for(int i=0; i < N; i++){
      	for(int j = 0; j < M; j++){
          	if (arr[i][j] == CHEESE){
              	cnt++;
  			}
  		}
  	}
      if (cnt){
      	lastCnt = cnt;
  	}
      return cnt ? false : true;
  
  }
  //BFS2()에서 표시한 칸을 공기로 바꾸는 과정
  void PreairToAir(void){
      for (int i = 0; i < N; i++){
      	for (int j = 0; j < M; j++){
          	if (arr[i][j] == PREAIR){
          		arr[i][j] = AIR;
  			}
  		}
  	}
  }
  
  //공기를 표시하는 과정
  void BFS1(void){
  
      memset(visited, 0, sizeof(visited));
      queue<pair<int, int> > q;
      q.push({ 0, 0 });
      while (!q.empty()){
          int y = q.front().first;
          int x = q.front().second;
          q.pop();
          for (int i = 0; i < 4; i++){
              int nextY = y + moveDir[i].y;
              int nextX = x + moveDir[i].x;
              if(0<=nextY && nextY < N && 0 <= nextX && nextX < M)
              if (!visited[nextY][nextX] && (!arr[nextY][nextX] || arr[nextY][nextX] == 3)){
                  arr[nextY][nextX] = AIR;
                  q.push({ nextY, nextX });
                  visited[nextY][nextX] = true;
              }
          }
      }
  }
  //곧 녹을 치즈를 표시하는 과정
  void BFS2(void){
      memset(visited, 0, sizeof(visited));
      queue<pair<int, int> > q;
      q.push({ 0, 0 });
  	while (!q.empty()){
          int y = q.front().first;
          int x = q.front().second;
          q.pop();
          for (int i = 0; i < 4; i++){
              int nextY = y + moveDir[i].y;
              int nextX = x + moveDir[i].x;
              if (0 <= nextY && nextY < N && 0 <= nextX && nextX < M && !visited[nextY][nextX]){
                  if (arr[nextY][nextX] == AIR){
                      q.push({ nextY, nextX });
                      visited[nextY][nextX] = true;
                  }
                  //곧 녹을 치즈를 표시하는 과정
                  if (arr[y][x] == AIR && arr[nextY][nextX] == CHEESE){
                      arr[nextY][nextX] = PREAIR;
                      q.push({ nextY, nextX });
                      visited[nextY][nextX] = true;
                  }
              }
          }
      }
  }
  
  int main(void){
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      cin >> N >> M;
      for (int i = 0; i < N; i++){
          for (int j = 0; j < M; j++){
              cin >> arr[i][j];
  		}
  	}
      int result = 0;
      while(1){
          if (allClear())
          break;
          BFS1();
          BFS2();
          PreairToAir();
          result++;
      }
      cout << result << "\n";
      cout << lastCnt << "\n";
      return 0;
  }
  ```

- #### 참고 출처 : <https://jaimemin.tistory.com/1032>

그러나 여러 번 고민을 한 결과 BFS를 2번 쓰지 않아도 문제를 풀 수 있었다. 문제는 바깥쪽의 1만 PREAIR로 바꾸는 것이기 때문에 굳이 모든 배열을 탐색할 필요가 없다. 따라서 1을 탐색했다면 PUSH해 다음 배열을 탐색하지 않고 1을 PREAIR로 상태변경만 해주면 1번의 BFS로도 문제를 풀 수 있으며, 탐색횟수 또한 효율적으로 줄일 수 있다.

- ```c++
  #include <iostream>
  #include <queue>
  #include <cstring>
  using namespace std;
  //애초에 AIR를 0으로 선언해 낭비를 줄인다.
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
                      // 바깥쪽이므로 안쪽을 탐색할 필요가 없다. 상태만 PREAIR로 변경한다.
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
  ```

  



### 2583. 영역구하기 ★

- 행렬로 대응하려면 (y,x)로 적용해야함 (하지않아도 되지만 개념상)

- 4칸 이동하기

  ```c++
  //1번째 방법 (x,y 이동값 정의)
  int dirx[4]={1,-1,0,0};
  int diry[4]={0,0,1,-1};
  for(int i=0;i<4;i++){
  		int next_y = start_y + diry[i];
  		int next_x = start_x + dirx[i];
  }
  //2번째 방법 (구조체 정의)
  typedef struct
  {
  	int y, x;
  }Dir;
  Dir moveDir[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
  for (int i = 0; i < 4; i++){
  	int next_y = start_y + moveDir[i].y;
  	int next_x = start_x + moveDir[i].x;
  }
  ```



### 느낀점

- **2636 치즈**문제가 BFS연습에 매우 좋은 문제였다. 다양한 상태를 위해 enum을 활용하여 BFS로 풀어야했고 다양한 접근방법이 있었다. 
- 많은 시간 고민을 해도 풀리지 않는 문제는 구글링을 통해 코드를 참고하여 공부했었다. 블로그의 설명과 코드에는 내가 생각하지 못한 접근방식과 스킬이 있었다. 때문에 참고한 블로그의 답이 항상 정해이고 최적의, 최선의 코드라고 생각했다. 하지만 이번 **2636 치즈**문제를 통해 코드 리팩토링을 통해 개선될 가능성이 있는 코드도 있다는 것을 알게 되었다. 내가 직접 고민해 개선했다는 점에서 뿌듯했다.