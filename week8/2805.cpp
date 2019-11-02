

#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

//int a[1000001];
int n,m;
vector<int> a;


int main(){
	//4 7
	scanf("%d %d", &n, &m);

	//20 15 10 17
	int num;
	for(int i = 0;i<n;i++){
		scanf("%d",&num);
		
		a.push_back(num);		
		
	}
	
	int begin = 0, last = 1e9;
	
	while(begin<= last){
		int mid = (begin+last)/2;
		
		long long tmp = 0;
		for(int i = 0;i<n;i++){
			if(a[i]-mid>0){
				tmp += a[i]-mid;
			}
		}

		
		if(tmp<m){
			
			last = mid-1;
		}else{
			begin = mid+1;

		}


	}
	
	
	printf("%d\n",last);
	return 0;
}