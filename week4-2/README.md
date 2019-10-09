# week4-1 다이나믹 프로그래밍

### 1. 11726 2xn 타일링

  - 2가지 경우의 수

      - i ) 마지막에 2x1 타일로 채우는 경우 DP[n-2]
      - ii ) 마지막에 1x2 타일로 채우는 경우 DP[n-1]

    따라서 DP[n]=DP[n-1]+DP[n-2]

### 2. 11727 2xn 타일링2 

 - 2가지 경우의 수

    - i ) 마지막에 2x2타일로 채우거나 2x1타일 2개로 채우는경우 
    - ii ) 마지막에 1x2타일로 채우는 경우

   따라서 DP[n]=DP[n-2] x 2 + DP[n-1]

### 3.  1912 연속합

- DP[i]는 arr[i]가 포함된 i까지의 최대합

  따라서 DP[n]=max(DP[n-1]+arr[n],arr[n])

  max값 변수를 따로 하나 선언해서 반복하며 maxnum=max(maxnum,DP[i])으로 최대 DP값 저장

### 4. 2293 동전 ★

- DP[n]=DP[n-Arr[0]]+DP[n-Arr[1]]+DP[n-Arr[2]].... 이런식으로 더하면 중복되는 경우가 발생
  ex)1+1+2+  1
       1+1+1+  2

  한번에 구하고 중복된 경우의 수를 빼주는 경우보다 **중복이 생기지 않는 경우의 수를 더하는 방식**이 더 효율적

- ``` c++
  #include <iostream>
  using namespace std;
  //최대 k는 10000, 동전 종류 최대 n은 100
  int dp[10001],arr[101],k,n;
  int main(){
      //아무것도 고르지 않았을 때 경우의 수 = 1
  	dp[0]=1; 
  	cin>>n>>k;
  	for(int i=0;i<n;i++){
  		cin>>arr[i];
  	}
  	for(int i=0;i<n;i++){
  		for(int j=arr[i];j<=k;j++){
  			dp[j]+=dp[j-arr[i]];
  		}
  	}
  	cout<<dp[k];
  }
  ```

- 참고 https://m.blog.naver.com/PostView.nhn?blogId=occidere&logNo=220784778900&proxyReferer=https%3A%2F%2Fwww.google.com%2F

  

### 5. 2156 포도주 시식 ★

- 2579 계단오르기 업그레이드 버전

- 연속해서 3잔을 마실 수 없고, 마지막 잔을 마신다는 조건이 없기 때문에 여러 경우의 수를 생각해야함

- 3가지 경우의 수

  - i ) n번째 잔을 마시고 n-1번째 잔을 마신경우 
  - ii ) n번째 잔을 마시고 n-1 번째 잔을 마시지 않은 경우 
  - iii ) n번째 잔을 마시지 않은 경우

  따라서 점화식은 다음과 같다.

  ```c++
  	for(int i=3;i<=n;i++){
  		dp[i]=max(dp[i-3]+arr[i-1]+arr[i],dp[i-2]+arr[i]);
  		dp[i]=max(dp[i-1],dp[i]);
  	}
  ```

- 참고 https://mygumi.tistory.com/98



### 6. 11052 카드 구매하기 ★

- 카드 1개가 들어있는 카드팩을 구매하고, 카드 n-1개를 구입한다.

  카드 2개가 들어있는 카드팩을 구매하고, 카드 n-2개를 구입한다.

  카드 3개가 들어있는 카드팩을 구매하고, 카드 n-3개를 구입한다.

  ​											...

  카드 n개가 들어있는 카드팩을 구매하고, 카드 n-n(0)개를 구입한다.

- 각 DP가 구해져있다고 가정할 경우

  ```c++
  for (int j = 1; j <=i; j++) {
  	DP[i] =max(DP[i], arr[j] + DP[i-j]);
  }
  ```

  각 DP를 구하면서 증가시켜야 하기 때문에 2중 for문을 통해 DP값을 구한다.

  ```C++
  for(int i=1;i<=n;i++){
  	for(int j=1;j<=i;j++){
  		DP[i]=max(DP[i],DP[i-j]+arr[j]);	
  	}
  }
  ```



### 7.  11053 가장 긴 증가하는 부분 수열 ★

- 현재 인덱스보다 작은 값을 탐색하면서 Arr[i] 보다 Arr[j]가 작을경우 DP[j]의 최대값을 구하여 DP[i]에 저장하면서 DP배열중 최대값을 출력한다

  ```c++
  for(int i=1;i<=n;i++){
  	for(int j=1;j<i;j++){
  		if(arr[i]>arr[j]){
  			if(dp[j]>maxnum){
  				maxnum=dp[j];
  			}
  		}
  	}
  	dp[i]=maxnum+1;
  	maxnum=0;
  	ans=max(dp[i],ans);
  }
  ```

  

- 참고

  - https://wootool.tistory.com/96
  - [https://namu.wiki/w/최장%20증가%20부분%20수열](https://namu.wiki/w/최장 증가 부분 수열)



### 느낀점

- DP문제를 풀 경우 시간복잡도를 O(n)이라고 생각하고  for문을 하나만 써야한다고 생각해서 못 푼 문제들이 많았다. **조건에 따라 2중 for문을 사용해야 하는 경우**가 있을 수 있기 때문에 그 부분도 고려해 보아야겠다.

- DP문제는 **여러 경우의 수를 생각해보는 것이 중요하다.** 맞다고 생각하고 짰는데 틀린 경우는 중복되는 경우 등 생각하지 못한 예외사항이 존재하는 경우가 대부분이었다.
- **꼭 DP[n]에 문제에서 원하는 정답을 담아야 하는 것은 아니다.** DP배열에 필요한 정보를 저장하고 max, min값을 통해 정답이 나오는 문제도 있다. (11053번 문제)









