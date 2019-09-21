
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n,m;
vector<pair<int,int>> house;
vector<pair<int,int>> chick;
int final_ans = 1e9;

void solve(string bit, int chick_cnt){
        if(bit.size()> (int)chick.size())return;
        
        int house_num = 0;

        int tmp;                
        if(chick_cnt == m){
                int sum = 0;
                for(int j = 0;j<house.size();j++){
                        int ans = 1e9;          
                        for(int i = 0;i<bit.size();i++){
                                if(bit[i] == '2'){
                                        ans = min(ans,abs(chick[i].first - house[j].first)+abs(chick[i].second - house[j].second));
                                }
                                
                        }
                        sum += ans;
                }
                final_ans = min(final_ans,sum);
                return;
        }
        
        solve(bit+"2",chick_cnt+1);
        solve(bit+"0",chick_cnt);
}
int main() {
        cin >> n >> m;
        
        

        for(int i = 0;i<n;i++){
                for(int j = 0;j<n;j++){
                        int t;
                        cin >> t;
                        if(t == 1){
                                house.push_back(make_pair(i,j));
                        }else if(t == 2){
                                chick.push_back(make_pair(i,j));
                        }
                }
        }
        solve("",0);
        cout << final_ans << endl;
        // your code goes here
        return 0;
}