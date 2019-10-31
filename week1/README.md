# WEEK1 탐색과 정렬 & 기초 자료구조

이번 주차는 첫주차라 문제의 난이도가 높지 않기 때문에 문제보단 개념위주로 정리한다.



### 탐색과 정렬

- 탐색과 각 정렬 방법에 대한 응용문제를 풀었다. 시간복잡도가 충족 되지 않으면 시간초과가 나기 때문에 이 유형의 문제들은 틀렸습니다 보다는 시간초과가 나는 유형이 많았다. 
- 기본적으로 정렬되어 있다고 가정할 때  O(nlgn)을 만족하는 이분탐색이 빠르다.
- 데이터의 범위가 제한되어 있는 걍우 숫자별로 횟수들의 합을 통해 출력하는 계수정렬은 O(N)으로 다른 정렬들 보다 빠르다.
- STL을 이용한 sort는 시간 복잡도 O(nlgn)을 갖는다. 비교할 때 compare함수를 직접 정의함으로서 비교방식을 자신이 정의 할 수 있다.
- 이분탐색에 대한 메서드도 제공해준다. (upper_bound, lower_bound) 



### 기초 자료구조

- 기본적으로 알아야할 자료구조 (스택, 큐, 덱 등)를 이용한 문제를 풀었다.
- 이미 알고있는 개념이지만 문제를 풀면서 왜 이 자료구조가 필요한지, 어떠한 상황에서 유용한지에 대해 다시금 개념을 잡았다.
- 자료구조 역시 STL에서 대부분 지원해주며, map이라는 자료구조도 지원해주기 때문에 key와 value를 이용한 저장이 가능하다. 



### 1016. 제곱ㄴㄴ수 ★★

- 에라토스테네스의 체를 응용한 문제.

- 제곱의 수로 나누어떨어지면 해당 배열을 1로 바꾸고 배열을 탐색하며 0일 경우 갯수를 세어 출력한다.

- 그러나 다음과 같은 문제점이 있다.

  - 범위가 1,000,000,000,000 (1조)이기 때문에 int형의 범위를 초과한다.
  - 범위가 1,000,000,000,000 (1조)이기 때문에 그 만큼의 배열을 선언 할 수 없다.

- 따라서 다음과 같이 접근하여 해결한다.

  - long long 형으로 선언하여 int를 초과하는 범위까지 계산한다.
  - max-min은 최대 1,000,000 이기때문에  사실상 알고 싶은 수의 갯수는 100만 이하이다. 따라서 그사이의 값만 계산하여 구해준다. 이 부분이 핵심이었다.

- ```c++
  #include <iostream>
  #include <math.h>  // sqrt()
  using namespace std;
  long long minnum,maxnum,cnt;
  bool arr[1000001];
  int main(){
  	cin>>minnum>>maxnum;
  	for(long long i=2;i<=sqrt(maxnum);i++){
  		long long x=minnum/(i*i);
  		if(minnum%(i*i)!=0){
  			x++;
  		}
  		while(x*i*i<=maxnum){
  			arr[x*i*i-minnum]=true;
  			x++;
  		}
  	}
  	for(int i=0;i<=maxnum-minnum;i++){
  		if(!arr[i]){
  			cnt++;
  		}
  	}
  	cout<<cnt;
  }
  ```

  

### 15711 환상의 짝꿍 ★★

- 수학적 지식이 필요한 문제.

  1. 골드바흐의 추측
     - 골드바흐의 추측은 **4보다 큰 모든 짝수는 두 홀수 소수의 합으로 나타낼 수 있다**는 추측이고 이것은 적당히 큰 수에 대해서 증명이 완료되었다. 
     - 따라서 4보다 큰 모든 짝수는 YES로 판별할 수 있다.
  2. 소수의 성질
     - 홀수+홀수=짝수 이므로, 소수끼리의 합은 모두 짝수가되고 모두 YES이다.
     - 당연히 아니다. 소수중 유일하게 짝수인 수가 있기때문이다. 바로 2이다.
     - 짝수(2)+홀수(소수)=홀수 이므로, 결과적으로 **A+B-2가 소수인지 판별**하면 된다.

- 그러나 A+B의 범위는 4,000,000,000,000(4조) 이기때문에 그 범위에 대해 전부 소수인지 판별할 수 는 없는 노릇이다. 그런데 잘 생각하보면 에라토스테네스 체를 이용하여 제곱근 범위 내에서만 소수를 구해주고 해당 수로 나누어 떨어질 경우 소수가 아니므로 NO, 나누어 떨어지지 않을 경우 YES를 출력하면 해결할 수 있다.

- ```C++
  #include <iostream>
  #include <math.h>
  #include <vector>
  using namespace std;
  int n;
  bool num[2000001];
  vector<int> v;
  void eratos(){
  	for(int i=2;i<=2000000;i++){
  		for(int j=i*2;j<=2000000;j+=i){
  			num[j]=true;
  		}
  	}
  }
  int main(){
  	eratos();
  	for(int i=2;i<=2000000;i++){
  		if(!num[i]){
  			v.push_back(i);
  		}
  	}
  	cin>>n;
  	for(int i=0;i<n;i++){
  		long long x,y;
  		cin>>x>>y;
  		long long z=x+y;
  		if(z<4){
  			cout<<"NO\n";
  		}else if(z%2==0){
  			cout<<"YES\n";
  		}else{
  			z-=2;
  			bool flag=false;
  			for(int i=0;i<v.size()&&(long long)v[i]*v[i]<=z;i++){
  				if(z%v[i]==0){
  					flag=true;
  					break;
  				}
  			}
  			if(flag==true){
  				cout<<"NO\n";
  			}else{
  				cout<<"YES\n";
  			}
  		}
  	}
  }
  ```

  

