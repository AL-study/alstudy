
#include <iostream>
#include <vector>
#include <queue>

#define max_int 100001

using namespace std;

int t, n, num, result;

// 정점 i의 indegree 수를 저장하는 배열
// ind[i]=j, 정점i의 indegree수는 j 입니다.

int ind[max_int];

int vv[max_int];

void init(){
    result = 0;
    for(int i=0; i<=n; i++){
        ind[i] = 0;
        vv[i] = 0;
    }
}

int main(){
    scanf("%d", &t);

    

    for(int test_case=1; test_case <= t; test_case++){
        scanf("%d", &n);

        init();


        for(int i=1; i<=n; i++){
            scanf("%d", &num);

            vv[i] = num;
     
            ind[num]++;
        
        }
        
        queue<int> q;
        for(int i=1; i<=n; i++){
            if(ind[i] == 0){
                q.push(i);
                result++;
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
                int next_ = vv[node];
                
                // indegree를 감소시켜줍니다.
                ind[next_]--;

                // indegree가 0이 되면 큐에 넣어줍니다.
                // 큐에 들어간다는 의미는 사이클에 속하지 않는다는 의미입니다.
                if(ind[next_] == 0) {
                    q.push(next_);
                    result++;
                }

        }

        printf("%d\n", result);
    }
}