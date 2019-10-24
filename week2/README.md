# WEEK2 BFS & DFS



### 백트래킹

- 모든 경우의 수를 전부 고려하는 알고리즘으로 상태공간을 **트리**로 나타낼 수 있을 때 적합한 방식이다.

- 방식에 따라서 DFS(Depth First Search, BFS(Breadth Frist Search) , BFS(Best First Search/Heuristic Search)이 있다.

- 모든 경우의 수를 고려해야 하는 문제라면 ( ex) N-Queen) DFS가 낫다. BFS도 가능 하지만 큐의 크기가 무지막지하게 커지기 대문에 일반적으로 DFS가 편리하다.

- 그러나 DFS를 절대 쓰면 안되는 경우가 있는데, 트리의 깊이가 무한대가 될 때이다. 미로찾기에서 루프(회로)가 발생하는 경우, DFS는 이 가지를 탈출할 수 없게 된다. 

- 최단거리 구하기에서는 BFS를 사용하는게 편리하다.

  #### 참고 출처: [나무위키/백트래킹]([https://namu.wiki/w/%EB%B0%B1%ED%8A%B8%EB%9E%98%ED%82%B9](https://namu.wiki/w/백트래킹))



### DFS

- DFS는 상태공간을 나타낸 트리에서 바닥에 도달할 때까지 한 쪽 방향으로만 내려가는 방식이다. 미로찾기를 생각하면 쉽다. 한 방향으로 들어갔다가 막다른 길에 다다르면(=트리의 바닥에 도착) 왔던 길을 돌아가서 다른 방향으로 간다. 이 짓을 목표지점(=원하는 해)이 나올 때까지 반복한다.
  재귀함수로 구현할 수 있으며, 재귀함수에 익숙하지 않다면 [스택](https://namu.wiki/w/스택)을 써서 할 수도 있다.

- 다음과 같은 알고리즘으로 구현이 가능하다

  1. 스택의 최상단 노드를 확인한다.
  2. 최산당 노드에게 방문하지 않은 인접 노드가 있으면 그 노드를 스택에 넣고 방문처리한다. 방문하지 않은 인접 노드가 없으면 스택에서 최상당 노드를 뺀다.

- 예제

  ```C++
  void dfs(int x){
      // 방문했는지 여부를 배열로 저장
      if(c[x]) return;
      // 방문처리
      c[x]=true;
      cout<<x<<" ";
      // 2번의 알고리즘에 해당
      for(int i=0;i<a[x].size();i++){
          int y=a[x][i];
          // 재귀방식으로 탐색 (스택으로도 구현가능)
          dfs(y);
      }
  }
  ```

- ####  참고 출처: [나동빈님의 네이버 블로그 / 2018 알고리즘 / 16. DFS ](https://blog.naver.com/ndb796/221230945092)

  

### BFS

- BFS는 모든 분기점을 다 검사하면서 진행하는 방식이다. 철수와 영희가 계단에서 가위바위보를 하며 ~~뻘짓~~게임을 하고 있을 때, 철수가 원하는 지점에 갈 수 있는 최소 승리 횟수는 얼마인가? 같은 문제에서 효과를 발휘한다. 이 경우 DFS는 깊이가 무한인 경우에 빠져나오지 못하며, 중복 방지를 한다고 치더라도 올바른 해를 찾는데 시간이 많이 걸린다. BFS는 모든 분기를 다 검색하면서 상태공간을 탐색한다. 철수가 이겼을 때, 비겼을 때, 졌을 때를 검사하고, 그 경우마다 각각 또다른 3가지 가능성을 전부 검사한다. 이러다가 어느 한 부분에서 원하는 해를 발견하면, 이것이 최단 거리가 된다.

- BFS는 [큐](https://namu.wiki/w/큐(자료구조))를 써서 구현한다. 각 경우를 검사하면서 발생하는 새로운 경우를 큐에 집어넣고, 검사한 원소는 큐에서 뺀다. BFS의 장점은 DFS가 못 건드리는 문제를 풀 수 있는 것이지만, 공간 복잡도가 지수 스케일로 폭발하기 때문에 가지치기를 제대로 안하면 DFS보다 빨리 오버플로우에 다다를 수 있다.

- 다음과 같은 알고리즘으로 구현이 가능하다

  1.  큐에서 하나의 노드를 꺼낸다.
  2.  해당 노드에 연결된 노드 중 방문하지 않은 노드를 방문하고, 차례대로 큐에 삽입한다.

- 예시 [BOJ 2667 단지번호붙이기](https://www.acmicpc.net/problem/2667)

  ```C++
  #include <iostream>
  #include <vector>
  #include <queue>
  #include <algorithm>
  
  using namespace std;
  int n;
  string arr[25];
  // 방문처리 배열
  bool check[25][25];
  vector<int> v;
  queue<pair<int, int > > q;
  // 이런식으로 행렬을 탐색 할때 4방향으로 탐색이 가능하다
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
              // 이런식으로 행렬을 탐색 할때 4방향으로 탐색이 가능하다
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
  ```



### 1967. 숨바꼭질

- BFS를 이용해 K값을 최소 횟수로 찾는 문제

- 정해진 깊이가 없기 때문에 DFS를 이용하면 무한루프 발생

- -1 , +1, x2 총 3가지 경우의 수 존재

- 이미 탐색했다면 다시 탐색할 필요가 없음

- ```c++
  #include <iostream>
  #include <queue>
  #include <vector>
  
  using namespace std;	
  int n,k,check[200001];
  queue<int> q;
  void bfs(int start){
  	q.push(start);
  	check[start]=0;
  	while(!q.empty()){
  		int x=q.front();
  		q.pop();
  		if(x==k){
  			cout<<check[k];
  			return;
  		}
          //(0<=x-1 && !check[x-1])의 순서를 바꾸면 런타임 에러 발생
          //배열값의 범위를 먼저 확인한 이후 배열값을 참조해야 한다.
  		if(0<=x-1 && !check[x-1]){
  			q.push(x-1);
  			check[x-1]=check[x]+1;
  		}
  		if(x+1 <= 200000 && !check[x+1]){
  			q.push(x+1);
  			check[x+1]=check[x]+1;
  		}
  		if(x*2 <=200000 && !check[x*2]){
  			q.push(x*2);
  			check[x*2]=check[x]+1;
  		}
  	}
  } 
  int main(){	
  	cin>>n>>k;
  	bfs(n);
  }
  ```

 

### 15686. 치킨거리 (삼성 SW역량 기출문제)

- 남겨야하는 치킨집의 수에 따라 해당 치킨집의 위치와 집의 위치를 저장해 완전탐색으로 최소의 거리를 더함

- **순열이 아닌 조합**을 통한 백트래킹 기법

- ```c++
  #include <iostream>
  #include <algorithm>
  #include <vector>
  #include <climits>
  using namespace std;
  int n,m,c,result=INT_MAX;
  vector<pair<int,int> > home, chicken;
  vector<int> v;
  int main(){
  	cin>>n>>m;
  	int arr[n][n];
  	for(int i=0;i<n;i++){
  		for(int j=0;j<n;j++){
  			cin>>arr[i][j];
  			if(arr[i][j]==2){
  				c++;
  				chicken.push_back({i,j});
  			}else if(arr[i][j] == 1){
  				home.push_back({i,j});
  			}
  		}
  	}
      //조합을 이용하기 위해 치킨집의 개수만큼 1을 push해준다.
  	for(int i=0;i<c-m;i++){
  		v.push_back(0);
  	}
  	for(int i=0;i<m;i++){
  		v.push_back(1);
  	}
  	do{
  		int ans=0;
  		for(int i=0;i<home.size();i++){
  			int minnum=INT_MAX;
  			for(int j=0;j<chicken.size();j++){
  				if(v[j]) minnum=min(minnum,abs(home[i].first-chicken[j].first)+abs(home[i].second-chicken[j].second));
  			}
  			ans+=minnum;
  		}
  		result=min(ans,result);
  	}while(next_permutation(v.begin(),v.end()));
  	cout<<result;
  	return 0;
  }
  ```



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

  

### 느낀점

- 백트래킹의 기본 개념과 관련 백준 문제들을 풀어보면서 DFS와 BFS의 개념을 어느정도 잡은 것 같다.
- 개념이 어렵게 느껴지진 않았지만 막상 구현을 해보니 생각보다 어렵게 느껴졌다. 많은 연습이 필요하다.
- DP나 정렬 등 접근 방법을 알면 빠르게 (적은 코드 양으로) 풀 수 있는 문제와는 달리 백트래킹은 생각보다 많은 구현량을 요구한다. 개념과 구현이 익숙해 질 때 까지 다양한 유형의 문제를 풀어보자.
- **2636 치즈**문제가 BFS연습에 매우 좋은 문제였다. 다양한 상태를 위해 enum을 활용하여 BFS로 풀어야했고 다양한 접근방법이 있었다. 
- 많은 시간 고민을 해도 풀리지 않는 문제는 구글링을 통해 코드를 참고하여 공부했었다. 블로그의 설명과 코드에는 내가 생각하지 못한 접근방식과 스킬이 있었다. 때문에 참고한 블로그의 답이 항상 정해이고 최적의, 최선의 코드라고 생각했다. 하지만 이번 **2636 치즈**문제를 통해 코드 리팩토링을 통해 개선될 가능성이 있는 코드도 있다는 것을 알게 되었다. 내가 직접 고민해 개선했다는 점에서 매우 뿌듯했다.
