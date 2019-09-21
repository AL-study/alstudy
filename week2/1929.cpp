
#include <cstdio>

using namespace std;
int p[1000001];
int pn = 0;
bool c[1000001];


int main() {
	// your code goes here
	int n,m;	
	scanf("%d %d",&m,&n);
	for(int i = 2;i<=n;i++){
		if(c[i] == false){
			p[pn++] = i;
		for(int j = i+i;j<=n;j+=i){
			c[j]  = true;
		}
		}
	}
	
	for(int i = 0;i<pn;i++){
		if(p[i] >= m){
			printf("%d\n",p[i]);
		}
	}
	
	
	return 0;
}