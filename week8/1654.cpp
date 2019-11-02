
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

//int a[1000001];
int k,n;
vector<int> a;


int main(){
	//4 11
	scanf("%d %d", &k, &n);

	//20 15 10 17
	int num;
	long long max = 0;

	for(int i = 0;i<k;i++){
		scanf("%d",&num);
		
		a.push_back(num);		
		if(max < a[i]){
			max = a[i];
		}	
	}

	long long ans = 0;
	//n개를 만들 수 있는 랜선의 최대 길이
	long long begin = 1, last = max;
	
	while(begin<= last){
		long long mid = (begin+last)/2;
		
		long long tmp = 0;
		for(int i = 0;i<k;i++){			
				tmp += a[i]/mid;	
		}

		
		if(tmp >= n){
			if(ans < mid){
				ans = mid;
			}
			begin = mid+1;
		}else{
			last = mid-1;

		}


	}
	
	
	printf("%lld\n",ans);
	return 0;
}