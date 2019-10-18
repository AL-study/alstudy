#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string com="<v>AB^CYv^XAZ";
string buttons[5]={"v>AB^CYv^XA","<v>A","^XAZ","Yv^XA",">AB^"};
int scores[5]={50,18,20,30,25};
int result;


int main(){

//	string str="hello ldlo me too";
//	
//	cout<<str.find("ello");
	
	// 1부터 6까지 담을 벡터
	vector<int> n;
	
	// 1부터 6까지 생성
	for(int i=0; i<6; i++){
		n.push_back(i+1);
	}

	// 0과1을 저장 할 벡터 생성
	vector<int> ind;

	// k=4, 4개를 뽑으니까
	int k = 3;
	
	while(k<6){
		// k개의 1 추가
		for(int i=0; i<k; i++){
			ind.push_back(1);
		}

	// 2개(6개-2개)의 0 추가
		for(int i=0; i<n.size()-k; i++){
			ind.push_back(0);
		}

	// 정렬
		sort(ind.begin(), ind.end());

	//순열
		do{
		// 출력
			for(int i=0; i<ind.size(); i++){
				if(ind[i] == 1){
					printf("%d ", n[i]);
				}
			}

			printf("\n");

		}while(next_permutation(ind.begin(), ind.end()));
	}
	
	

	return 0;
		

}

