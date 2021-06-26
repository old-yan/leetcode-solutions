#include "utils.h"

class Solution {
    typedef long long ll;
    unordered_map<ll,int>M[9];
    ll batchSize;
    //cur表示目前左边的余数，state表示剩余顾客的分布
    int dfs(int cur,ll state){
        if(M[cur].count(state))return M[cur][state];
        if(!state)return M[cur][state]=0;
        int res=0;
        for(int i=1;i<batchSize;i++){
            //如果还有余数为i的顾客，就尝试令他作为下一波顾客
            if((state>>(i*5))%32){
                int temp=dfs((cur+i)%batchSize,state-(1ll<<(i*5)));
                res=max(res,cur?temp:temp+1);
            }
        }
        return M[cur][state]=res;
    }
public:
    //本题需进行状态压缩+记忆化搜索
    //字太多写不下，可以看我力扣的题解
    int maxHappyGroups(int _batchSize, vector<int>& groups) {
        batchSize=_batchSize;
        ll state=0;
        int mod0=0;
        for(int a:groups){
            a%=batchSize;
            if(!a)mod0++;//余数为0直接贪心作为最左边的顾客
            else state+=1ll<<(a*5);
        }
        return mod0+dfs(0,state);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int batchSize=3;
    vi groups{1,2,3};
    auto ans=sol.maxHappyGroups(batchSize,groups);
    DBG(ans);

    system("pause");
    return 0;
}
