
#include <cstdio>
#include <algorithm>

using namespace std;

int a[301];
int d[301];

int main() {
	// your code goes here
	int T;
	scanf("%d",&T);
	
	a[0] = 0;
	
	for(int i = 1;i<=T;i++){
		scanf("%d",&a[i]);
	}
	
	d[1] = a[1];
	d[2] = a[1] + a[2];
	
	for(int i = 3;i<=T;i++){
		d[i] = max(d[i-2]+a[i],d[i-3]+a[i-1]+a[i]);		
	}
	
	printf("%d\n",d[T]);
	
	return 0;
}
