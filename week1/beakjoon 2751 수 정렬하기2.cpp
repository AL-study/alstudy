#include <iostream>
using namespace std;
int sorted[1000000];

void merge(int *data,int start,int middle,int end){
	int i=start,k=start,j=middle+1;
	while(i<=middle&&j<=end){
		if(data[i]>=data[j]){
			sorted[k]=data[j];
			j++;
		}else{
			sorted[k]=data[i];
			i++;
		}
		k++;
	}
	if(i>middle){
		for(int t=j;t<=end;t++){
			sorted[k]=data[t];
			k++;
		}
	}else{
		for(int t=i;t<=middle;t++){
			sorted[k]=data[t];
			k++;
		}
	}
	for(int t=start;t<=end;t++){
		data[t]=sorted[t];
	}

}

void mergesort(int *data,int start,int end){
	if(start<end){
		int middle=(start+end)/2;
		mergesort(data,start,middle);
		mergesort(data,middle+1,end);
		merge(data,start,middle,end);
	}
}

int main(void){
    int n;
    cin>>n;
    int data[n];

    for(int i=0;i<n;i++){
        cin>>data[i];
    }
    mergesort(data,0,n-1);
	for(int i=0;i<n;i++){
		cout<<data[i]<<' ';
	}
	return 0;
}
