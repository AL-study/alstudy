#include <iostream>
#include <string>

using namespace std;

int n;
string num;

void permutation(char c, int cnt){
    if (cnt - 1 == n){
        cout << num << "\n";
        exit(0);
    }
    num += c;
    for (int i = 1; i <= cnt / 2; i++){
        string a = num.substr(cnt - i, i);
        string b = num.substr(cnt - i * 2, i);
        
		//³ª»Û ¼ö¿­
        if (a == b){
            num.erase(cnt - 1);
            return;
        }
    }
    for (int i = 1; i <= 3; i++){
    	permutation(i + '0', cnt + 1);
	}
	
    num.erase(cnt - 1); 
}


int main(){
	cin >> n;
	for(int i = 1; i <= 3; i++){
		permutation(i + '0', 1);
	}
    return 0;
}
