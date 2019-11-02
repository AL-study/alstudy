
#include <deque>
#include <string>
#include <cstdio>
#include <iostream>
#include <vector>


using namespace std;

int main() {
	
	int t;

	cin >> t;	
	while(t--){
		int reverse = 0;
		int flag = 0;
		string ans;
		string str;
		char aaa[100005];
		int num;
		char tmp;
		int a;
		deque<int> dq;
		deque<int> tmpdq;
		
//		cin >> str;
//		scanf("%s",str); // RDD
			scanf("%s", &aaa);
		str = aaa;
		scanf("%d",&num);

		scanf(" %c",&tmp);
	
		for(int i = 0;i<num;i++){
			scanf(" %d,",&a);
			dq.push_back(a);//1 2 3 4
		}
		scanf(" %c",&tmp);
	
		for(int i = 0;i<str.size();i++){
			
			 
			if(str[i] == 'R'){//뒤집기
			
				reverse = !reverse;
			
			}else if(str[i] == 'D'){
				if (dq.empty()) { flag = 1; break; }
				
				
				if(reverse == 0){
					dq.pop_front();	
				}else{
					dq.pop_back();
				}
				
				
			}
			
		}
		if (flag == 1) { printf("error\n"); continue; }
		
		printf("[");
		
		if (dq.empty()){ 
			printf("]\n"); 
			continue; 
			
		} 

		if (reverse == 0) {
			for (int i = 0; i < dq.size() - 1; i++) {
				printf("%d,", dq[i]); 
				
			} 
			printf("%d]\n", dq[dq.size() - 1]);
		}
		else if (reverse == 1) {
			for (int i = dq.size() - 1; i > 0; i--) { 
				printf("%d,", dq[i]); 
				
			} printf("%d]\n", dq[0]); 
			
		} 
		
	}
	return 0;
}