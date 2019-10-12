
#include <cstdio>
    using namespace std;
     
    int d[10001];
    int a[101];
     
    int main() {
    	int n,k;
     
        scanf("%d %d", &n, &k);
        
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
     
    	d[0] =1;
	
	for(int j=1;j<=n;j++){	
		for(int i = 1;i<=k;i++){//a[j]부터 시작
			if(i-a[j] >= 0){
            d[i] += d[i-a[j]];               
            }	
 
		}
	}
     
    	printf("%d\n",d[k]);
    	return 0;
    }