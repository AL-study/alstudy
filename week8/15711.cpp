
#include <cstdio>

using namespace std;
typedef long long ll;

bool prime (ll n){
	if(n < 2){
		return false;
	}

	for(int i = 2; i<2*1e12 && 2*i<=n;i++){
		if(n%i == 0){
			return false;
		}
	}
	return true;
}

int main(){
	int t;
	scanf("%d",&t);
	

	while(t--){	
		ll n1,n2;
		bool ans = false;
		
		scanf("%lld %lld", &n1, &n2);
		
		if((n1+n2) < 4){printf("NO\n");continue;}
		
		if((n1+n2)%2 ==0){printf("YES\n");continue;}
		
		for(int i = 1;i<=n1+n2;i++){
			if(prime(i)&&prime(n1+n2-i)){
				ans = true;
				break;
			}
		}
		
		
		if(ans){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
		
	}
	return 0;
}