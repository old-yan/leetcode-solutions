#include "utils.h"

class Solution {
public:
    //本题和双周赛T4一样，要使用离线查询
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        //将区间按照开始时间排序
        sort(ALL(intervals));
        //将queries的下标按照升序排列
        vi idxes(queries.size());
        iota(ALL(idxes),0);
        sort(ALL(idxes),[&](int x,int y){return queries[x]<queries[y];});
        vi ans(queries.size());
        //使用S、S2保存当前已经进入考虑范围，且未失效的那些区间
        multiset<pair<int,int>>S;   //pair={区间尾，区间长}
        multiset<int>S2;    //int={区间长}
        //cur表示目前准备考虑加入备选范围的intervals下标
        int cur=0;
        //按升序枚举query
        for(int idx:idxes){
            int q=queries[idx];
            //query越来越大，那么我们就要将更多的区间纳入备选范围
            while(cur<intervals.size()&&intervals[cur][0]<=q){
                S.emplace(intervals[cur][1],intervals[cur][1]-intervals[cur][0]+1);
                S2.emplace(intervals[cur][1]-intervals[cur][0]+1);
                cur++;
            }
            //在招新的时候，也要除旧，把过时的区间扔出去
            while(S.size()&&S.begin()->first<q){
                S2.erase(S2.find(S.begin()->second));
                S.erase(S.begin());
            }
            ans[idx]=S2.size()?*S2.begin():-1;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi intervals=makevvi("[[4,5],[5,8],[1,9],[8,10],[1,6]]");
    vi queries{7,9,3,9,3};
    auto ans=sol.minInterval(intervals,queries);
    DBGV(ans);

    system("pause");
    return 0;
}
