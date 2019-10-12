
#include <cstdio>
#include <algorithm>

using namespace std;

int a[10001];
int d[10001];

int main() {
	// your code goes here
	int n;
	scanf("%d",&n);
	
	a[0] = 0;
	
	for(int i = 1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	
	d[0] = 0;
	d[1] = a[1];
	d[2] = a[1]+ a[2];
	
	for(int i = 3;i<=n;i++){
		d[i] = max(d[i], d[i-1]);
		d[i] = max(d[i], d[i-2]+a[i]);
		d[i] = max(d[i],d[i-3]+a[i-1]+a[i]);
		
	}
	
	printf("%d\n",d[n]);
	
	return 0;
}