#include <vector>
#include <iostream>
using namespace std;
int n,s;
int cnt = 0;
void go(vector<int> &a,int index, int ans) {
	if (a[index]+ans == s)
		cnt += 1;

	if (n-1 == index)
        return;
    
    
    go(a,index+1,ans);
    go(a,index+1,ans+a[index]);
    
    
}
int main() {
    cin >> n >> s;
    vector<int> a(n);
    
    for(int i = 0;i<n;i++){
    	cin >> a[i];
    }
    go(a,0,0);
    
    cout << cnt << endl;
    return 0;
}