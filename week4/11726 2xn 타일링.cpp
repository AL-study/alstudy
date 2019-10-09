#include <iostream>
using namespace std;

int Solve(int n, int * smallAnswer)
{
    smallAnswer[1] = 1;
    smallAnswer[2] = 2;
    
    for(int i=3;i<=n;i++){
        smallAnswer[i] = (smallAnswer[i-1] + smallAnswer[i-2]) % 10007;
    }
    
    return smallAnswer[n];
}
int main(){
    int arr[1000001];
    int n;
    scanf("%d", &n);
    
    cout << Solve(n,arr);
    return 0;
}