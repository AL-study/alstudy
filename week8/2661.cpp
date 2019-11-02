
#include<iostream>
#include<string>
using namespace std;
int n;
bool finish;
bool check(string s) {
    int len = s.length();
    int start = len - 1;
    
 
    for (int i = 1;i<=len/2;i++) {
    	
        	string first = s.substr(start - i, i);
        	string second = s.substr(start, i);

        	if(first == second)return false;
        	--start;
			
    }
    return true;
}
void go(int len, string s) {
    if (finish) return;
    if (!check(s)) return;
    if (len == n) {
        finish = true;
        cout << s << endl;
        return;
    }
    go(len + 1, s + "1");
    go(len + 1, s + "2");
    go(len + 1, s + "3");
}
int main() {
    cin >> n;
    go(0, "");
    return 0;
}
 
