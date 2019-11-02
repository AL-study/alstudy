#include <cstdio>

using namespace std;

int main() {
	

	int cnt;
	
	scanf("%d", &cnt);
	
	int min = 1000000;
	int max = -1;
	
	while(cnt--){
		int num;		
		scanf("%d",&num);
		if(max < num){
			max = num;
		}
		if(min >= num){
			min = num;
		}
	}
	
	printf("%lld\n",1LL*max*min);
	
	return 0;
}