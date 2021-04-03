#include "utils.h"

class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        int cur=0;
        REP(i,8)if(cells[i])cur|=(1<<i);
        unordered_map<int,int>M;
        M[cur]=0;
        for(int day=1;day<=n;day++){
            int next=0;
            FOR(i,1,7){
                if((cur>>(i-1)&1)==(cur>>(i+1)&1)){
                    next|=(1<<i);
                }
            }
            cur=next;
            if(day==n)break;
            if(M.count(cur)&&(n-cur)%(day-M[cur])==0)break;
            else M[cur]=day;
        }
        vi ans(8,0);
        REP(i,8)if(cur>>i&1)ans[i]=1;
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi cells{0,1,0,1,1,0,0,1};
    int N=1000000000;
    auto ans=sol.prisonAfterNDays(cells,N);
    DBGV(ans);

    system("pause");
    return 0;
}
