# week4-2 DFS & BFS

### 1. 2206 벽부수고 이동하기



### 2. 7578 토마토



### 3. 7569 토마토



### 4. 9466 팀 프로젝트



### 5. 2636 치즈



### 6. 2583 영역구하기 ★

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

