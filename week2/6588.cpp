
#include <cstdio>

bool c[999995];
int p[999995];
int pn = 0;

int main()
{
	for(int i = 2;i<=1000000;i++){
		if(c[i] == false){
			p[pn++] = i;
			for(int j = i+i;j<=1000000;j+=i){
				c[j] = true;
			}
		}
	}
		
	int n;
	scanf("%d", &n);
	int ca= 0;
	while(n != 0 && ca <= 100000){
		ca++;
		
		int tmp = 0;
		int ans_a = 0;
		int ans_b = 0;
		
		for(int i = 0;i<=n;i++){
			if(c[n-p[i]] == false){
				printf("%d = %d + %d \n", n,p[i], n-p[i]);
				break;
			}
		}
		
	
		scanf("%d", &n);
	}
	
	
	return 0;
}