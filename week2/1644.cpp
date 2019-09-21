
#include <iostream>
#include <vector>
using namespace std;

int pn = 0;// 소수 개수
bool c[4000001];
int n;
int sum;
int ans;
vector<int> a;
//에라토스테네스의 체는 보통은 sqrt(N)만큼만 확인해서 소수임을 판별하는 데 사용하는 경우가 대부분인데, 이 문제에서는 sqrt(N)을 넘어가는 숫자들의 합으로 N이 될 수 있으므로, N만큼 확인해봐야한다.

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	
	for(int i = 2;i<=n;i++){
		if(c[i] == false){
			a.push_back(i);

			for(int j = i+i;j<=n;j+=i){
				c[j] = true;
			}
		}
	}
	
	
	int left = 0;
	int right = 0;
	while(1){
		
		while(sum < n && right < a.size()){
			sum += a[right++];
		}
		
		while(sum >= n && left<right){
			if(sum == n){
				ans += 1;
			}
			sum -=a[left++];
		}
		
		if(right == a.size()){
			break;
		}
	}
	
	cout << ans << "\n";
	return 0;
}