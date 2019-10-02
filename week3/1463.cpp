
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int d[1000001];

int main() {
	// your code goes here
	int num;
	scanf("%d", &num);
	
	
	
	d[0] = 0;
	d[1] = 0;

	
	 for (int i=2; i<=num; i++) {
        d[i] = d[i-1]+1;
        if (i % 2 == 0) {
            d[i] = min(d[i],d[i/2]+1);
        }
        if (i % 3 == 0) {
            d[i] = min(d[i/3]+1,d[i]);
        }
    }
    
	printf("%d\n", d[num]);
	
	return 0;
}