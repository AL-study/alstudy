#include <iostream>
#include <vector>

using namespace std;

int n,row,col,maxrow;
string type;

int main(){
	
	cin>>n>>type;
	vector <pair <int,string> > v;
	for(int i=0;i<n;i++){
		int tempnum;
		string tempstr;
		cin>>tempnum;
		cin>>tempstr;
		v.push_back({tempnum, tempstr});
	}
	
	for(int i=0;i<v.size();i++){
		row=max(v[i].first*2-1,row);
		col+=v[i].first*v[i].second.length();
	}
	
	char arr[row][col];
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			arr[i][j]='.';
		}
	}
	int now_row=0,now_col=0;
	int start_row,end_row, mid_row, start_col, end_col;
	for(int i=0;i<v.size();i++){
		for(int j=0;j<v[i].second.length();j++){
			if(type=="MIDDLE"){
				start_row=(row+1)/2-v[i].first;
				end_row=(row+1)/2-v[i].first;
				end_row=row-end_row;
				mid_row=(end_row+start_row)/2;
				start_col=now_col;
				end_col=now_col+v[i].first-1;
				//cout<<"sr:"<<start_row<<"  er:"<<end_row<<"   row:"<<row<<"\n";
			}else if(type=="BOTTOM"){
				start_row=((row+1)/2-v[i].first)*2;
				end_row=row;
				mid_row=(end_row+start_row)/2;
				start_col=now_col;
				end_col=now_col+v[i].first-1;
				//cout<<"sr:"<<start_row<<"  er:"<<end_row<<"   row:"<<row<<"\n";
			}else{
				start_row=0;
				end_row=v[i].first*2-1;
				mid_row=end_row/2;
				start_col=now_col;
				end_col=now_col+v[i].first-1;
			}
			
			if(v[i].second[j]=='1'){
				for(int k=start_row;k<end_row;k++) arr[k][end_col]='#';
				now_col+=v[i].first;
			}
			else if(v[i].second[j]=='2'){
				for(int k=start_row;k<mid_row;k++) arr[k][end_col]='#';
				for(int k=mid_row;k<end_row;k++) arr[k][start_col]='#';
				for(int k=0;k<v[i].first;k++) arr[start_row][now_col+k]='#';
				for(int k=0;k<v[i].first;k++) arr[mid_row][now_col+k]='#';
				for(int k=0;k<v[i].first;k++) arr[end_row-1][now_col+k]='#';
				now_col+=v[i].first;
			}else if(v[i].second[j]=='3'){
				for(int k=start_row;k<end_row;k++) arr[k][end_col]='#';
				for(int k=0;k<v[i].first;k++) arr[start_row][now_col+k]='#';
				for(int k=0;k<v[i].first;k++) arr[mid_row][now_col+k]='#';
				for(int k=0;k<v[i].first;k++) arr[end_row-1][now_col+k]='#';
				now_col+=v[i].first;
			}
			else if(v[i].second[j]=='4'){
				for(int k=start_row;k<end_row;k++) arr[k][end_col]='#';
				for(int k=start_row;k<mid_row;k++) arr[k][start_col]='#';
				for(int k=0;k<v[i].first;k++) arr[mid_row][now_col+k]='#';
				now_col+=v[i].first;
			}else if(v[i].second[j]=='5'){
				for(int k=start_row;k<mid_row;k++) arr[k][start_col]='#';
				for(int k=mid_row;k<end_row;k++) arr[k][end_col]='#';
				for(int k=0;k<v[i].first;k++) arr[start_row][now_col+k]='#';
				for(int k=0;k<v[i].first;k++) arr[mid_row][now_col+k]='#';
				for(int k=0;k<v[i].first;k++) arr[end_row-1][now_col+k]='#';
				now_col+=v[i].first;
			}else if(v[i].second[j]=='6'){
				for(int k=0;k<v[i].first;k++) arr[mid_row][now_col+k]='#';
				for(int k=0;k<v[i].first;k++) arr[end_row-1][now_col+k]='#';
				for(int k=start_row;k<end_row;k++) arr[k][start_col]='#';
				for(int k=mid_row;k<end_row;k++) arr[k][end_col]='#';
				now_col+=v[i].first;
			}else if(v[i].second[j]=='7'){
				for(int k=0;k<v[i].first;k++) arr[start_row][now_col+k]='#';
				for(int k=start_row;k<end_row;k++) arr[k][end_col]='#';
				now_col+=v[i].first;
			}
			else if(v[i].second[j]=='8'){
				for(int k=0;k<v[i].first;k++) arr[start_row][now_col+k]='#';
				for(int k=0;k<v[i].first;k++) arr[mid_row][now_col+k]='#';
				for(int k=0;k<v[i].first;k++) arr[end_row-1][now_col+k]='#';
				for(int k=start_row;k<end_row;k++) arr[k][start_col]='#';
				for(int k=start_row;k<end_row;k++) arr[k][end_col]='#';
				now_col+=v[i].first;
			}
			else if(v[i].second[j]=='9'){
				for(int k=0;k<v[i].first;k++) arr[start_row][now_col+k]='#';
				for(int k=0;k<v[i].first;k++) arr[mid_row][now_col+k]='#';
				for(int k=start_row;k<mid_row;k++) arr[k][start_col]='#';
				for(int k=start_row;k<end_row;k++) arr[k][end_col]='#';
				now_col+=v[i].first;
			}else if(v[i].second[j]=='0'){
				for(int k=0;k<v[i].first;k++) arr[start_row][now_col+k]='#';
				for(int k=0;k<v[i].first;k++) arr[end_row-1][now_col+k]='#';
				for(int k=start_row;k<end_row;k++) arr[k][start_col]='#';
				for(int k=start_row;k<end_row;k++) arr[k][end_col]='#';
				now_col+=v[i].first;
			}
		}
	}
	int nr=0,nc=0;
	for(int l=0;l<row;l++){
		for(int i=0;i<v.size();i++){
			for(int j=0;j<v[i].second.length();j++){
				for(int k=0;k<v[i].first;k++){
					cout<<arr[nr][nc];
					nc++;
				}
				cout<<" ";
			}
		}
		cout<<"\n";
		nr++;
		nc=0;
	}
	
	
	
	
	
}

//4 TOP
//5 123
//3 45
//5 7890
//3 6

//4 MIDDLE
//5 123
//3 45
//5 7890
//3 6

//4 BOTTOM
//5 123
//3 45
//5 7890
//3 6




