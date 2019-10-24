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
