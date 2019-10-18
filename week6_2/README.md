# WEEK6_2  힙

힙은 우선 순위 큐를 위하여 만들어진 자료구조다. 그럼 먼저 우선순위 큐가 무엇이고 어떻게 쓰이는지 알아보자.

![img](https://gmlwjd9405.github.io/images/data-structure-heap/data-structure-heap-compare.png)

-  우선순위 큐의 이용 사례

  - 시뮬레이션 시스템
  - 네트워크 트래픽 제어
  - 운영 체제에서의 작업 스케쥴링
  - 수치 해석적인 계산

- 우선수위 큐는 배열, 연결리스트, 힙 으로 구현이 가능하다. 이중에서 힙으로 구하는 것이 가장 효율적이다.

  ![img](https://gmlwjd9405.github.io/images/data-structure-heap/data-structure-heap-priorityqueue.png)



### 자료구조 '힙(heap)'이란?

- **완전 이진 트리의 일종으로** 우선순위 큐를 위하여 만들어진 자료구조이다.

- 여러 개의 값들 중에서 **최댓값이나 최솟값을 빠르게** 찾아내도록 만들어진 자료구조이다.

- 힙 트리에서는 **중복된 값을 허용**한다. (이진 탐색 트리에서는 중복된 값을 허용하지 않는다.)

  

### 힙(heap)의 종류

- 최대 힙(max heap)
  - 부모 노드의 키 값이 자식 노드의 키 값보다 크거나 같은 완전 이진 트리
  - key(부모 노드) >= key(자식 노드)
- 최소 힙(min heap)
  - 부모 노드의 키 값이 자식 노드의 키 값보다 작거나 같은 완전 이진 트리
  - key(부모 노드) <= key(자식 노드)
- ![img](https://gmlwjd9405.github.io/images/data-structure-heap/types-of-heap.png)



### 힙(heap)의 구현

- 힙을 저장하는 표준적인 자료구조는 배열 이다.
- 구현을 쉽게 하기 위하여 배열의 첫 번째 인덱스인 0은 사용되지 않는다.
- 특정 위치의 노드 번호는 새로운 노드가 추가되어도 변하지 않는다.
  - 예를 들어 루트 노드의 오른쪽 노드의 번호는 항상 3이다.

- 힙에서의 부모 노드와 자식 노드의 관계

  - 왼쪽 자식의 인덱스 = (부모의 인덱스) * 2

  - 오른쪽 자식의 인덱스 = (부모의 인덱스) * 2 + 1

  - 부모의 인덱스 = (자식의 인덱스) / 2

  - ![img](https://gmlwjd9405.github.io/images/data-structure-heap/heap-index-parent-child.png)

    

### 힙(heap)의 삽입

1. 힙에 새로운 요소가 들어오면, 일단 새로운 노드를 힙의 마지막 노드에 이어서 삽입한다.

2. 새로운 노드를 부모 노드들과 교환해서 힙의 성질을 만족시킨다.

   아래의 최대 힙(max heap)에 새로운 요소 8을 삽입해보자.
   

![img](https://gmlwjd9405.github.io/images/data-structure-heap/maxheap-insertion.png)



### 힙(heap)의 삭제

1. 최대 힙에서 최댓값은 루트 노드이므로 루트 노드가 삭제된다.
   (최대 힙(max heap)에서 삭제 연산은 최댓값을 가진 요소를 삭제하는 것이다.)

2. 삭제된 루트 노드에는 힙의 마지막 노드를 가져온다.

3. 힙을 재구성한다.

   아래의 최대 힙(max heap)에서 최댓값을 삭제해보자.

![img](https://gmlwjd9405.github.io/images/data-structure-heap/maxheap-delete.png)



#### 참고 출처 : <https://gmlwjd9405.github.io/2018/05/10/data-structure-heap.html>

개념정리가 매우 잘 되어 있는 블로그가 있었다. 코드도 있지만 코드는 따라치기보다 개념을 먼저 이해하고 직접 구현해보자.



### STL priority queue

하지만 힙은 이미 구현체로 정의되어 있다. ~~(STL이라 쓰고 갓이라 읽는다.)~~

우선순위 큐는 실제로는 **priority_queue<자료형, 구현체, 비교 연산자>**로 정의한다. 비교연산자 디폴트값은 less로 최대힙이다. 최소힙으로 바꾸고 싶다면 다음과 같이 선언하자.

```c++
priority_queue <int, vector<int>,greater<int> > pq
```

최소힙 최대힙이 아닌 특수한 조건이 필요한 경우 직접 정의해 사용 할 수 있다.

```c++
#include <cstdio>
#include <queue>
using namespace std;
struct a{
    int start;
    int end;
    int value;
};
struct cmp{
    bool operator()(a t, a u){
        return t.value < u.value;
    }
};
priority_queue<a,vector<a>,cmp> pq;
```

cmp 클래스를 만들어서 연산자를 저렇게 만들고, priority_queue에 overload하면 저게 less<int> 구실을 대신 해준다.

#### 참고 출처: https://koosaga.com/9



### 1927. 최소힙

- 힙의 기본 개념을 알고 있고 구현 할 수 있는지 묻는 문제이다. STL라이브러리의 priority_queue를 쓰고 싶다면 디폴트 비교 연산자가 less(최대힙)이기 때문에 greater로 바꾸어 주어야 한다.

- ```c++
  #include <iostream>
  #include <vector>
  #include <queue>
  using namespace std;
  int n; 
  priority_queue <int, vector<int>,greater<int> > pq;
  int main(){
  	ios_base :: sync_with_stdio(false);
  	cin.tie(NULL);
  	cout.tie(NULL);
  	cin>>n;
  	for(int i=0;i<n;i++){
  		int temp;
  		cin>>temp;
  		if(temp==0){
  			if(pq.empty()){
  				cout<<"0\n";
  			}else{
  				cout<<pq.top()<<"\n";
  
  				pq.pop();
  			}
  		}else{
  			pq.push(temp);
  		}
      }
  } 
  
  ```



### 11279. 최대힙

- 1927 최소힙 문제와 같다. 최대힙 이므로 비교 연산자를 따로 정의해 줄 필요가 없다.

- 소스코드는 위와 똑같고 우선순위 큐선언시에 다음과 같이 정의하면 된다.

  ```c++
  priority_queue <int> pq;
  ```



### 11286. 절대값 힙

- 우선순위 큐에 절대값으로 넣는 대신 부호를 판단하기 위해 < 절대값 , 1 or -1 >로 push한다.

- 그 이후 판단은 위의 문제와 비슷하지만 주의 할 점이 있는데 greater <pair <int , int> > 로 넣으면 연산자의 우선순위는 first를 먼저 비교하고 second를 비교한다. greater이외에 자신이 구조체를 정의하여 사용 할 수 도 있다.

- ```c++
  #include <iostream>
  #include <vector>
  #include <queue>
  
  using namespace std;
  int n; 
  priority_queue < pair<int, int>, vector<pair<int, int> >, greater<pair<int,int> > > pq;
  int main(){
  	ios_base :: sync_with_stdio(false);
  	cin.tie(NULL);
  	cout.tie(NULL);
  	cin>>n;
  	
  	for(int i=0;i<n;i++){
  		int temp;
  		cin>>temp;
  		if(temp==0){
  			if(pq.empty()){
  				cout<<"0\n";
  			}else{
  				if(pq.top().second==-1){
  					cout<<pq.top().first*-1<<"\n";
  				}else{
  					cout<<pq.top().first<<"\n";
  				}
  				pq.pop();
  			}
  		}else{
  			if(temp>=0){
  				pq.push({temp,1});
  			}else{
  				pq.push({temp*-1,-1});
  			}
  		}
  	}
  }
  ```



### 1715. 카드 정렬하기 ★

- 문제를 이해하지 못해 틀린문제... 정렬된 카드뭉치를 뭉칠때 비교횟수가 최소가 되게 만들어야 한다.

- 힙을 이용하여 그리디적인 방식으로 접근해 풀었다.

- 최소의 비교횟수를 위해 가장 작은 수의 카드 뭉치 끼리 뭉쳐서 다시 우선 순위 큐에 push한다.

- ```c++
  #include <iostream>
  #include <vector>
  #include <queue>
  
  using namespace std;
  int n,sum; 
  priority_queue< int, vector<int>, greater<int> > pq;
  
  int main(){
  	ios_base :: sync_with_stdio(false);
  	cin.tie(NULL);
  	cout.tie(NULL);
  	cin>>n;
  	for(int i=0;i<n;i++){
  		int temp;
  		cin>>temp;
  		pq.push(temp);
  	}
  	while(!pq.empty()){
  		if(pq.size()==1){
  			cout<<sum;
  			exit(0);
  		}
  		int t1=pq.top();
  		pq.pop();
  		t1+=pq.top();
  		pq.pop();
  		sum+=t1;
  		pq.push(t1);
  	}
  }
  ```



### 1655. 가운데를 말해요 ★★

- 수가 들어올 때 마다 갱신되는 중앙값을 출력해야 하는 문제

- 처음 접한 유형이라 그런지 접근방법이 매우 어려웠다.

- 처음 접근했을 때는 중앙값이 루트값에 오는 힙을 생각했다.

  - 하지만 중앙 값이 루트값에 오는 힙을 구현하는 것이 어려웠다.
  - 구글링 해보니 AVL 트리, Red-Black 트리 등 다양한 트리가 있었다.
  - 힙만으로 풀고 싶었고 문제도 위의 트리 구현을 원하는 문제는 아닌 것 같았다.

- 힙으로 이 문제를 풀기 위해선 **최대 힙과 절대 힙 2개의 힙을 이용**하여 중앙값을 구한다.

  1. maxheap의 크기가 minheap의 크기와 같거나, maxheap이 1 더 크다.
  2. maxheap의 모든 원소는 minheap의 모든 원소보다 작거나 같다.
     = maxheap.top() <= minheap.top()

- ```c++
  #include <iostream>
  #include <vector>
  #include <queue>
  
  using namespace std;
  int n,sum,change=1; 
  priority_queue<int, vector<int>, greater<int> > pq_min;
  priority_queue<int> pq_max;
  
  int main(){
  	ios_base :: sync_with_stdio(false);
  	cin.tie(NULL);
  	cout.tie(NULL);
  	cin>>n;
  	for(int i=0;i<n;i++){
  		int temp;
  		cin>>temp;
  		// 1. maxheap의 크기가 minheap의 크기와 같거나, maxheap이 1 더 크다. 
  		if(pq_max.size()==pq_min.size()){
  			pq_max.push(temp);
  		}else{
  			pq_min.push(temp);
  		}
  		// 2. maxheap의 top은 minheap의 top보다 작거나 같다. 
  		if(!pq_max.empty()&&!pq_min.empty()&&pq_max.top()>pq_min.top()){
  			int pq_max_top=pq_max.top(), pq_min_top=pq_min.top();
  			pq_max.pop(),pq_min.pop();
  			pq_max.push(pq_min_top);
  			pq_min.push(pq_max_top);
  		}
  		cout<<pq_max.top()<<"\n";
  	}
  }
  ```

  

### 느낀점

- 힙의 개념을 알고 있다면 대부분 어렵지 않게 풀 수 있는 문제였다. (1655번 문제 제외)
- STL라이브러리의 Priority_queue의 사용법과 비교연산자를 정의 하는 방법을 배웠다.
- 1655번 문제가 이번 힙 문제의 핵심이었다. 매 과정마다 중간값을 뽑는 걸 하나의 힙으로 해결하려고 했지만 구글링을 통해 여러 코드를 찾아보니 대부분 최소힙, 최대힙 2가지를 응용하여 풀었다.
- 접근방법이 어려워서 이해하는데 시간이 오래 걸렸다. 많은 유형을 풀어서 익숙해져야 할 것 같다.

