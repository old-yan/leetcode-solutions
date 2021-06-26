#include "utils.h"

class Solution {
    struct presum{
        ll sum[100001]={0};
        presum(int*begin,int*end){
            REP(i,end-begin){
                sum[i+1]=sum[i]+begin[i];
            }
        }
        ll query(int l,int r){
            return sum[r+1]-sum[l];
        }
    };
public:
    //预处理出packages的前缀和，然后用box去把packages分区间计算
    int minWastedSpace(vector<int>& packages, vector<vector<int>>& boxes) {
        presum helper(&packages[0],&packages[0]+packages.size());
        int n=packages.size(),m=boxes.size();
        sort(ALL(packages));
        int Maxa=packages.back();
        ll ans=LLONG_MAX;
        for(auto&b:boxes){
            sort(ALL(b));
            //如果装不下最大的货物，直接放弃
            if(b.back()<packages.back())continue;
            //cur表示当前要从哪个箱子开始装（之前的都已经装完了）
            int cur=0;
            ll cnt=0;
            for(int a:b){
                //next表示下一个装不下的货物
                int next=upper_bound(packages.begin(),packages.end(),a)-packages.begin();
                //将[cur,next)区间的货物统计好
                cnt+=(ll)a*(next-cur)-helper.query(cur,next-1);
                cur=next;
            }
            chmin(ans,cnt);
        }
        if(ans==LLONG_MAX)return -1;
        else return ans%MOD;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi packages{2,3,5};
    vvi boxes=makevvi("[[4,8],[2,8]]");
    auto ans=sol.minWastedSpace(packages,boxes);
    DBG(ans);

    system("pause");
    return 0;
}
