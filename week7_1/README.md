# README

[TOC]

## 7st - 1



> 10. 19~ 10.23



---

### 4.3 힙



#### [1927 최소 힙](https://github.com/soyalan/Algorithm/blob/master/AlgorithmStudy/7st_1/1927.cpp)

> ```cpp
> priority_queue<int, vector<int>, greater<int> > q;
> ```
>
> priority queue 사용
>
> greater를 이용해 순서대로 정렬



#### [11279 최대 힙](https://github.com/soyalan/Algorithm/blob/master/AlgorithmStudy/7st_1/11279.cpp)

> 최소 힙과 동일
>
> less는 기본값으로 설정되어있음
>
> ```cpp
> priority_queue<int> q;
> ```



#### [11286 절댓값 힙](https://github.com/soyalan/Algorithm/blob/master/AlgorithmStudy/7st_1/11286.cpp)

> 클래스의 연산자 오버로딩을 통해 큐 우선순위 설정



#### [1715 카드 정렬하기](https://github.com/soyalan/Algorithm/blob/master/AlgorithmStudy/7st_1/1715.cpp)

> 계속 최소값을 더해가면 됨



#### [1655 가운데를 말해요](https://github.com/soyalan/Algorithm/blob/master/AlgorithmStudy/7st_1/1655.cpp)

> 가운데 값을 기준으로 작은 값, 큰 값을 나눠 저장