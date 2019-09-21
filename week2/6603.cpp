
#include <vector>
#include <cstdio>
using namespace std;
vector<int> ans;
void solve(vector<int> &a,int n, int index, int cnt) {
    if (cnt == 6) {
        for (int num : ans) {
            printf("%d ",num);
        }
        printf("\n");
        return;
    }
    
    if (n <= index) return;
    
    ans.push_back(a[index]);
    solve(a,n,index+1,cnt+1);
    ans.pop_back();
    solve(a,n,index+1,cnt);
}
int main() {
    while (true) {
        int n;
        scanf("%d ",&n);
        
        if (n == 0) break;
        vector<int> a(n);
        for (int i=0; i<n; i++) {
            scanf("%d ",&a[i]);
        }
        solve(a,n, 0, 0);
        printf("\n");
    }
    return 0;
}
