
#include <cstdio>
#include <algorithm>

using namespace std;

int n;
int d[501][501];

int main(){
	scanf("%d",&n);
	
	int result = -1;

	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=i;j++){
			scanf("%d",&d[i][j]);
		}
	}
	
	
    for(int i = 2; i <= n; i++) {
      for(int j = 1; j <= i; j++) {
        if(j == 1) //한 경로
          d[i][j] += d[i-1][j];
        else if(j == i)//한 경로
          d[i][j] += d[i-1][j-1];
        else//두 경로 중 큰 값에서 내려오는 경로
          d[i][j] += max(d[i-1][j],d[i-1][j-1]);
      }
    }
    
    for(int i = 1;i<=n;i++){
    	result = max(result,d[n][i]);
    }
    

   
	printf("%d\n", result);

return 0;
}