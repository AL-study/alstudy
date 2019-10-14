# week6 파라메트릭 서치

-  파라메트릭 서치는 이분 탐색과 매우 유사하지만 사실 다른 개념이다.  가장 큰 차이점으로는 파라메트릭 서치는 **최적화 문제를 결정 문제**로 바꾸어 푸는것 이다.

- 예시를 통한 파라메트릭 서치
  **문제)**

  자동차를 탈 수 있는 사람중 나이가 가장 어린 사람을 찾고자 한다.

  이때 자동차를 탈 수 있는 사람이라 함은 나이가 19세 이상이라고 가정한다.

  (즉, 19세 이상은 모두 탈 수 있다고 한다.)

  가장 어린 사람의 번호는 몇번인가?

  **전제)**

  사람이 나열되어있고 이 사람들은 나이순으로 정렬되어있다.

  이렇게 문제가 주어진다면, 이 문제를 결정 문제로 바꿀 수 있을까?

  **결정 문제**로 바꾸어보자.

  **-> 자동차를 탈 수 있나요?**

  ![예시1](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=http%3A%2F%2Fcfile24.uf.tistory.com%2Fimage%2F99A1BC3359BA935F1ACDBC)

  

  ![예시2](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=http%3A%2F%2Fcfile25.uf.tistory.com%2Fimage%2F9973833359BA935F0A81D6)

  

  ![예시3](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=http%3A%2F%2Fcfile23.uf.tistory.com%2Fimage%2F99AC663359BA936038FD23)

  ![예시4](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=http%3A%2F%2Fcfile22.uf.tistory.com%2Fimage%2F993E783359BA93613FC465)

  

  

  참고 출처: <https://www.crocus.co.kr/1000>

- 이처럼 **최적화 문제를 결정 문제**로 바꾸어 생각해 푸는 것을 말하는데 그 과정은 이분 탐색과 유사하며 시간복잡도 역시 O(lgN)을 갖는다.



### 1. 2805 나무자르기

- 배열의 값을 탐색하는 것이 아닌 **잘라야하는 나무의 높이**를 이분 탐색하며 최대의 높이를 찾는다.

- 높이의 범위가 1,000,000,000이기 때문에 overflow를 방지하기 위해 long long형으로 계산한다.

- ```C++
  long long result =0;
  	while(low <= height){
  		long long mid=(low+height)/2;
  		if(arrsum(arr,mid)){
  			result=max(result,mid);
  			low=mid+1;
  		}else{
  			height=mid-1;
  		}
  	}
  ```



### 2. 1654 랜선 자르기

- 2805문제와 마찬가지로 배열값을 탐색하는 것이 아닌 **잘라야하는 랜선의 길이**를 이분 탐색하여 최대의 길이를 찾는 문제였다.

- 같은 로직이지만 나무자르기와 같이 짜면 **틀렸습니다**가 나오는데 그 이유는 k=1,n=1, 2147483647 (INT_MAX 값)의 반례가 존재하기 때문에 low, height, mid 값을 long long 형으로 선언해야 한다. 

- climits 헤더는 다양한 자료형의 Min, Max값을 제공하는 라이브러리이다. 
  참고자료: [climits 레퍼런스](http://www.cplusplus.com/reference/climits/)

- ```c++
  #include <iostream>
  #include <climits>
  using namespace std;
  int k,n;
  //climits 라이브러리를 이용한 INT_MAX값
  long long low,height=INT_MAX;
  bool possible(int arr[],long long mid){
  	long long num=0;
  	for(int i=0;i<k;i++){
  		num+=arr[i]/mid;
  	}
  	if(num>=n)return true;
  	else return false;
  }
  int main(){
  	cin>>k>>n;
  	int arr[k];
  	for(int i=0;i<k;i++){
  		cin>>arr[i];
  		if(height<arr[i]){
  			height=arr[i];
  		}
  	}
  	long long result=0;
  	while(low<=height){
  		long long mid=(low+height)/2;	
  		if(possible(arr,mid)){
  			low=mid+1;
  			result=max(result,mid);
  		}else{
  			height=mid-1;
  		}
  	}
  	cout<<result;
  }
  ```

### 3. 











### 느낀점

- 이분탐색과 파라메트릭 서치는 이분탐색을 이용하여 답을 찾는점에서 유사하지만 최적화문제를 결정문제로 바꾸어 푸는 점에서 다르다.
- 배열의 값을 정렬한 후 이분탐색을 하지 않고 최대혹은 최소의 값을 찾기위해 주어진 값을 이분탐색을 통해 정답을 찾는 문제도 있었다. 문제에서 무엇을 요구하는지 정확히 짚고 생각해보자.
- BOJ(백준 온라인 저지)는 틀렸을 경우 (런타임 에러, 시간초과, 틀렸습니다 등) 질문 검색을 통해 다양한 반례를 찾을 수 있다. 정답을 보지 말고 질문 검색을 통해 코드 리팩토링을  계속 시도해보자.