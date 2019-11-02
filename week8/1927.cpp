
#include <cstdio>
#include <queue>
#include <algorithm>
#include <functional>

using namespace std;

int n;
typedef long long ll;

priority_queue<ll,vector<ll>,greater<ll>> q;//작은것부터 출력
int main(){
	
	scanf("%d",&n);

	for(int j = 0;j<n;j++){
		ll i;
		scanf("%lld",&i);
		if(!i){
			if(q.empty())printf("0\n");
			else{
				printf("%lld\n",q.top());
				q.pop();
			}
		}else{
			q.push(i);
		}
	}

	return 0;
}
