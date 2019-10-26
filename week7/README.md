# week7 그리디 2

현재의 상황에서 항상 최선의 값만을 생각하여 푸는 방식으로 개념자체가 어렵진 않지만, 보통 다양한 알고리즘과 응용되어 나오기 때문에 난이도가 높은 문제는 상당히 까다롭다.



### 1202. 보석도둑 ★★

- 그리디 + 힙 응용문제.

- 힙을 쓸 생각을 못하고 그리디적인 방법으로만 접근을 해서 **시간초과** 발생

  - 보석의 가치를 기준으로 정렬하고 해당 가방의 무게보다 같거나 낮은경우 추가하고 -1로 값 변경
  - 배열의 삭제는 O(n)이기 때문에 -1로 바꾸었지만 개수가 줄어드는게 아니기 때문에 결과적으론 개수만큼 다시 탐색하므로 **시간초과** 발생

- 힙을 이용할 경우

  - 가방의 무게를 기준으로 정렬 why? -> 가능한 무게별로 정렬 후 최대힙에 보석의 가치를 넣음으로서 최대 가치의 합을 구할 수 있기 때문
  - index값을 변수에 저장해 우선순위 큐에 push마다 값을 증가하며 가방의 개수 만큼 반복실행
  - 저장된 최대힙을 가방의 개수만큼 pop해 result변수에 더함. 이때 우선순위 큐가 비었는지 확인을 해야함

- ```c++
  #include <iostream>
  #include <algorithm>
  #include <vector>
  #include <queue>
  
  using namespace std;
  
  int n,k;
  // 범위를 생각해보자 int형을 초과할 것이다.
  long long ans;
  // default는 최대힙
  priority_queue <int> pq;
  int main(){
  	ios_base :: sync_with_stdio(false);
  	cin.tie(NULL);
  	cout.tie(NULL);
  	cin>>n>>k;
  	vector <pair<int, int > > jewel; 
  	vector<int> bag;
  	
  	for(int i=0;i<n;i++){
  		int temp1,temp2;
  		cin>>temp1>>temp2;
  		jewel.push_back({temp1,temp2});
  	}
  	for(int j=0;j<k;j++){
  		int temp1;
  		cin>>temp1;
  		bag.push_back(temp1);
  	}
  	sort(jewel.begin(),jewel.end());
  	sort(bag.begin(),bag.end());
  	// 이처럼 for문안에 여러개의 변수를 선언해 사용가능
  	for(int i=0,j=0;i<k;i++){
  		while(j<n&&jewel[j].first<=bag[i]){
  			pq.push(jewel[j++].second);
  		}
          // 우선순위 큐가 비었는지 확인한 후 진행해야 한다. 아닐시 런타임에러!
  		if (!pq.empty()) {
              ans += pq.top();
              pq.pop();
          }
  	}
  	cout<<ans;
  }
  ```



### 9576. 책 나눠주기

- **1931 회의실 문제**와 같은 유형의 문제. b를 기존으로 오름차순 정렬한 상태에서 책을 나눠준다.

- ```c++
  #include <iostream>
  #include <algorithm>
  #include <vector>
  using namespace std;
  int t,n,m;
  bool arr[1001];
  bool compare(pair<int, int> a, pair<int, int> b){	
  	if(a.second==b.second){
  		return a.first<b.first;	
  	}else{
  		return a.second<b.second;
  	}	
  }
  int main(){
  	vector <pair<int, int> > v;
  	cin>>t;
  	for(int i=0;i<t;i++){
  		memset(arr,false,sizeof(arr));
  		int ans=0;
  		cin>>n>>m;
  		v.clear();
  		for(int j=0;j<m;j++){
  			int temp1,temp2;
  			cin>>temp1>>temp2;
  			v.push_back({temp1,temp2});
  		}
  		sort(v.begin(),v.end(),compare);
  		
  		for(int j=0;j<v.size();j++){
  			for(int k=v[j].first;k<=v[j].second;k++){
  				if(!arr[k]){
  					arr[k]=true;
  					ans++;
  					break;
  				}
  			}
  		}
  		cout<<ans<<"\n";
  	}
  } 
  ```



### 13305. 주유소

- 전형적인 그리디 문제. 다음 도시의 연료값이 더 싸다면 다음 연료를 주유해주고 min값을 갱신

- 싸지 않다면 현재 min값 * edge(도시간 거리) 만큼을 ans(결과값)에 더함

- 범위가 1,000,000,000이기 때문에 ans값은 long long형으로 선언

- ```c++
  #include <iostream>
  #include <climits> // INT_MAX 사용
  using namespace std;
  int n,edge[100001],ver[100001];
  long long ans,minnum=INT_MAX;
  int main(){
  	cin>>n;
  	for(int i=0;i<n-1;i++){
  		cin>>edge[i];
  	}
  	for(int i=0;i<n;i++){
  		cin>>ver[i];
  		if(minnum>ver[i]){
  			minnum=ver[i];
  			ans+=minnum*edge[i];
  		}else{
  			ans+=minnum*edge[i];
  		}
  	}
  	cout<<ans;
  }
  ```



### 1826. 연료 채우기 ★

현재위치를 계속 바꿔나가면서 여러 요소들을 고려하다 보니 예외사항(반례)에 많이 막혔다. 힙을 이용한 그리디문제. 구글링해보니 DP, 2개의 힙을 이용하신 분 등등 다양한 풀이법이 존재했다.

- 힙을 이용해 그리디하게 접근 할 경우

  - 주유소의 정보를 받아 거리를 기준으로 sorting한 뒤 내가 현재 갈 수 있는 거리내에 있는 모든 주유소의 데이터를 우선순위 큐에 push
  - 이후 그리디하게 갈 수 있는 주유소중 가장 큰 연료량을 가지는 주유소를 선택

- ```c++
  #include <iostream>
  #include <vector>
  #include <algorithm>
  #include <queue>
  using namespace std;
  int n,l,p,ans,now,maxnum,idx,i;
  vector<pair <int, int > > v;
  priority_queue<int> pq;
  int main(){
  	cin>>n;
  	for(int i=0;i<n;i++){
  		int temp1,temp2;
  		cin>>temp1>>temp2;
  		v.push_back({temp1,temp2});
  	}
  	cin>>l>>p;
  	sort(v.begin(),v.end());
  	while (p < l) {
          while (v[i].first <= p) {
              if (i == n)break;
              pq.push(v[i].second);
              i++;
          }
          if (!pq.size())break;
          ans++;
          p += pq.top();
          pq.pop();
      }
      if(p>=l){
      	cout<<ans;
  	}else{
  		cout<<-1;
  	}
  } 
  ```



### 1422. 숫자의 신

정렬하는 과정을 그리디적인 방식으로 접근해 푼 문제다. 정렬방식이 까다롭고, 반례가 많아 생각을 많이 해봐야한다. 정답 비율도 적은데 푼 사람 자체가 적어 질문 검색에도 반례가 제시되어 있지 않았다. 오로지 혼자 생각해서 풀어야했는데 반나절정도 걸렸다. (~~다음생엔 천재로 태어나자~~)

- 문제를 읽어보면 알다싶이 1이상 100,000,000이하의 자연수를 합쳐야 하기 때문에 string으로 해결해야 한다.

- ```c++
  #include <iostream>
  #include <algorithm>
  #include <sstream>
  using namespace std;
  int k,n;
  string str[1001];
  string ans;
  
  bool compare(string a,string b){
  	return a+b>b+a;
  }
  int main(){
  	cin>>k>>n;
  	string num[k];
  	int gon=0,idx=0;
  	for(int i=0;i<k;i++){
  		cin>>num[i];
  	}
  	sort(num,num+k,compare);
  	if(n==k){
  		for(int i=0;i<k;i++){
  			ans+=num[i];
  		}
  	}else{
  		for(int i=0;i<k;i++){
  			if(gon<atoi(num[i].c_str())){
  				gon=atoi(num[i].c_str());
  				idx=i;
  			}
  		}
  		for(int i=0;i<k;i++){
  			if(i==idx){
  				for(int j=0;j<n-k;j++){
                      // 버전문제로 to_string(int value)가 안먹혀서 sstream을 이용했다.
  					stringstream s;
  					s<<gon;
  					ans+=s.str();
  				}
  			}
  			ans+=num[i];
  		}
  	}
  	cout<<ans;
  }
  ```



# 보너스 문제 (BOJ 15595 정답 비율 계산하기)

코드 제출 이후 틀렸다면 보통 질문 검색을 통해 반례를 찾거나 자신과 같은 문제로 고생하는 사람의 질문중 '해결됨'표시가 되어 있는 글을 열람한다. 질문 검색을 클릭하면 공통 공지사항으로 올라와 있는 글이 있다. 그중 채점 결과 FAQ를 보면 BOJ가 어떤식으로 채점을 하고, 정답 비율을 계산하는지 등 백준을 풀어본 사람이면 누구나 궁금해 할 만한 것들에 대해 설명되어 있다. (https://www.acmicpc.net/blog/view/55) 

그중 문제의 정답 비율의 계산방식에 대한 답변은 다음과 같이 써져있다.

--- ---

Q. **문제의 정답 비율은 어떻게 계산되나요?**

A. https://www.acmicpc.net/problem/15595

---

(~~그냥 방법이 알고 싶었을 뿐인데....~~) 그렇게 문제를 풀게 되었다. 

문제에 들어가면 정답 비율을 어떻게 계산하는지 바로 알 수 있다. 정답 비율 = (문제를 맞은 사람의 수) / (문제를 맞은 사람의 수 + (문제를 맞은 각 사람이 그 문제를 맞기 전까지 틀린 횟수의 총 합)) × 100 

즉 정답 비율은 오로지 문제를 맞힌 사람에 한에서만 영향을 미치며, 정답 비율이 낮을수록 문제를 푼 사람이 많은 시행착오를 겪었다는 뜻으로 해석 할 수 있다.

### 주의사항

1. 이미 정답을 맞힌 아이디에 대해서는 이후에 오답을 제출하더라도 정답률에 반영되지 않는다.
2. 정답을 아직 맞추지 못한 아이디에 대해서도 정답률에 반영되지 않는다.
3. 소수점 오차범위를 지정해 주어야 한다.
4. 예시로 테스트케이스를 주는데 출력예시는 무시하고 조건만 충족시키면 된다.

난이도가 높은편은 아니기 때문에 주의사항만 잘 지킨다면 어렵지 않게 풀 수 있다.

```c++
#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
using namespace std;
int ansnum,answnum;
map <string ,pair<int,int> > m;

int main(){
	int n;
	cin>>n;
	string nam;
	for(int i=0; i<n;i++){
		string pn,name;
		int ans,mem,time,lan,cleng;
		cin>>pn>>name>>ans>>mem>>time>>lan>>cleng;
		if(ans==4){
			m[name].first+=1;
		}else{
            // 주의사항1 : 이미 정답을 맞힌 아이디에 대해서는 이후에 오답을 제출하더라도 
            //           정답률에 반영되지 않는다.
			if(m[name].first==0){
				m[name].second+=1;
			}
		}
	}
	map<string, pair<int, int> >::iterator it;
	for(it = m.begin(); it != m.end(); it++){
		if(it->first=="megalusion"){
			continue;
		}
        // 주의사항2 : 정답을 아직 맞추지 못한 아이디에 대해서도 정답률에 반영되지 않는다.
		if(it->second.first>0){
			ansnum++;
			answnum+=it->second.second;
		}
	}
	if(ansnum+answnum==0){
		cout<<0;
	}else{
		int sub=ansnum+answnum;
        // 주의사항3 : 소수점 오차범위를 지정해 주어야 한다. 
		printf("%.12g\n",(double)ansnum/(double)(sub)*100.0);
	}
}
```



### 느낀점

- 그리디 문제를 풀때마다 느끼는 거지만 쉬운 문제는 바로바로 풀리는데 여러 알고리즘을 응용한 문제는 어려워 생각을 많이 해야 풀린다. (전부다 그렇겠지만...)
- 우선순위 큐, 조건부 string 정렬등 많은 알고리즘이 응용되어 나올 수 있고, 이 때 예외처리를 잘 해야주어야 한다. 반례를 많이 생각해보고 반례가 없다면 예외처리에 대해 다시 고민해보자.