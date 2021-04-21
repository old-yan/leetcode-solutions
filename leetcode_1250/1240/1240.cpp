#include "utils.h"

class Solution {
    int m,n,ans=INT_MAX;
    int cnt[30];
    void dfs(int curcost){
        if(curcost>=ans)return;
        int begin=min_element(cnt,cnt+n)-cnt;
        if(cnt[begin]==m){
            chmin(ans,curcost);
        }
        else{
            int end=begin+1;
            while(end<begin+m-cnt[begin]&&cnt[end]==cnt[begin])end++;
            FOR(j,begin,end)cnt[j]+=end-begin;
            for(int i=end-1,w=i-begin+1;i>=begin;i--,w--){
                dfs(curcost+1);
                FOR(j,begin,i)cnt[j]--;;
                cnt[i]-=w;
            }
        }
    }
public:
    int tilingRectangle(int _m, int _n){
        m=_m,n=_n;
        memset(cnt,0,sizeof(cnt));
        cnt[n]=INT_MAX;
        dfs(0);
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int m=11;
    int n=13;
    auto ans=sol.tilingRectangle(m,n);
    DBG(ans);

    system("pause");
    return 0;
}
