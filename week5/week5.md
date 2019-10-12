# 4-1. 그리디 알고리즘(1)

#### 2019/10/12



### [11047 동전 0](https://github.com/AL-study/alstudy/tree/yw/week5/boj11047.cpp)

- 금액이 가장 큰 동전부터 사용 가능한 개수를 카운팅하고,사용한 만큼 잔액의 금액을 뺀다.



### [1931 회의실배정](https://github.com/AL-study/alstudy/tree/yw/week5/boj1931.cpp)

- 초기 아이디어

  1. 회의 시작 시간을 기준으로 정렬.
  2. 재귀를 통해 모든 경우의 수 탐색.

  => 시간초과.

- [참고 풀이](https://ryute.tistory.com/10)
  1. 회의 종료 시간을 기준으로 정렬.
  2. 이전 회의 종료 시간보다 이후 회의 시작 시간이 크거나 같으면 카운팅.

### [2217 로프](https://github.com/AL-study/alstudy/tree/yw/week5/boj2217.cpp)

- 로프를 오름차순 후, 인덱스 별로 해당 로프가 index+1개가 있을 때 로프들이 버틸 수 있는 최대 중량.

### [2529 부등호](https://github.com/AL-study/alstudy/tree/yw/week5/boj2529.cpp)

- prev_permutation을 이용해 최대값, next_permutation을 이용해 최소값 구하기.