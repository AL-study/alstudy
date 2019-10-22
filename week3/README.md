# WEEK3 다이나믹 프로그래밍

다이나믹의 프로그래밍의 핵심은 **메모이제이션**이다. 이 메모이제이션을 이용함으로써 상상도 못 할 만큼의 연산량을 줄여주기도 한다. ( ex) 피보나치 수열 ) 그럼 메모이제이션에 대해 알아보자.

### 메모이제이션

- **한 번 계산한 결과를 메모리에 저장**해 두었다가 꺼내 씀으로써 **중복 계산을 방지**할 수 있게 하는 기법
- 동적 계획법의 핵심이 되는 기술로써 결국 메모리라는 공간 비용을 투입해 계산에 소용되는 시간 비용을 줄이는 방식

- 보통 n항을 알고 싶으면 1~n-1항 까지의 답을 담을 수 있는 배열을 선언해야 하기 때문에 n개 만큼의 배열을 선언한다.

### 1003 피보나치 함수

- 이 문제를 풀어보면 왜 메모이제이션 기법을 써야하는지 이해 할 수 있다.

- ```c++
  #include <iostream>
  #include <vector>
  using namespace std;
  int n;
  vector<pair <int ,int > > v(41);
  int main(){
  	ios_base :: sync_with_stdio(false);
      cin.tie(NULL);
      cout.tie(NULL);
      // 메모이제이션
  	v[0].first=1;
  	v[0].second=0;
  	v[1].first=0;
  	v[1].second=1;
  	v[2].first=1;
  	v[2].second=1;
  	for(int i=3;i<41;i++){
  		v[i].first=v[i-1].first+v[i-2].first;
  		v[i].second=v[i-1].second+v[i-2].second;
  	}
  	cin>>n;
  	for(int i=0;i<n;i++){
  		int temp;
  		cin>>temp;
  		cout<<v[temp].first<<" "<<v[temp].second<<"\n";
  	}
  }
  ```



### 2579 계단 오르기

- 여러 경우의 수를 생각해야 했기 때문에 까다로웠던 문제

  1. n-1번째 계단을 밟았을 경우
     - 이 경우는 n-2번째 계단을 밟았는지의 유무를 알 수 없으므로 n-3 번재 계단을 밟았을 경우로 생각한다. n-3 번재 계단을 밟았을 경우는 n-1번째, n 번재 계단을 밟으면 되기 때문에 dp[i-3]+arr[i-1]+arr[i]
  2. n-2번째 계단을 밟았을 경우
     - 이 경우 끝 계단인 n번째 계단을 밟으면 되기 때문에 dp[i-2]+arr[i]

- ```c+=
  #include <iostream>
  #include <vector>
  
  using namespace std;
  
  int n,dp[301],arr[301];
  int main(){
  	cin>>n;
  	for(int i=1;i<=n;i++){
  		cin>>arr[i];
  	}
  	dp[1]=arr[1];
  	dp[2]=arr[1]+arr[2];
  	dp[3]=max(arr[1]+arr[3],arr[2]+arr[3]);
  	for(int i=4;i<=n;i++){
  		dp[i]=max(dp[i-3]+arr[i]+arr[i-1],dp[i-2]+arr[i]);
  	}
  	cout<<dp[n];
  }
  ```



### 1149 RGB거리

- 3가지 색의 경우의 수를 따져야 하기 때문에 dp배열이 N X 3이 필요했다.

- 각 색을 선택했을 경우에 따라 각 dp배열에 최소값을 비교하여 저장한다.

- ```c++
  #include <iostream>
  using namespace std;
  int n,dp[1001][3],arr[1001][3];
  int main(){
  	cin>>n;
  	for(int i=0;i<n;i++){
  		cin>>arr[i][0];
  		cin>>arr[i][1];
  		cin>>arr[i][2];
  	}
  	dp[0][0]=arr[0][0];
  	dp[0][1]=arr[0][1];
  	dp[0][2]=arr[0][2];
  	for(int i=1;i<n;i++){
  		dp[i][0]=min(dp[i-1][1]+arr[i][0],dp[i-1][2]+arr[i][0]);
  		dp[i][1]=min(dp[i-1][0]+arr[i][1],dp[i-1][2]+arr[i][1]);
  		dp[i][2]=min(dp[i-1][0]+arr[i][2],dp[i-1][1]+arr[i][2]);
  	}
  	cout<<min(min(dp[n-1][0],dp[n-1][1]),dp[n-1][2]);
  }
  ```



### 느낀점

- 메모이제이션을 활용하여 시간복잡도가 O(n)으로 줄어든다. 시간초과가 난다면 대부분 메모이제이션을 잘 못했거나 잘못 접근한 경우였다.
- 틀렸습니다가 나올 경우는 모든 경우의 수를 생각 못 한 경우이다. 반례를 생각해보자.
- 기초수준의 문제라 나름 수월하게 풀었던것 같다.