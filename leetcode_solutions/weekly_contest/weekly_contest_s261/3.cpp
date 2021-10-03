#include "utils.h"

class Solution {
    int cnt[3]={0};
    //dfs参数：p表示当前选手，cursum表示当前的和
    bool dfs(int p,int cursum){
        //如果当前轮到 bob ，即使无路可走也算赢
        if(p==1 and cnt[0]==0 and cnt[1]==0 and cnt[2]==0)return true;
        //否则的话分情况讨论即可
        //cursum=0，可以拿1或2
        if(!cursum){
            for(int i:{1,2})if(cnt[i]){
                cnt[i]--;
                bool b=dfs(p^1,cursum+i);
                cnt[i]++;
                if(!b)return true;
            }
            return false;
        }
        //cursum=1，可以拿0或1
        else if(cursum%3==1){
            for(int i:{0,1})if(cnt[i]){
                cnt[i]--;
                bool b=dfs(p^1,cursum+i);
                cnt[i]++;
                return !b;
            }
            return false;
        }
        //cursum=2，可以拿0或2
        else{
            for(int i:{0,2})if(cnt[i]){
                cnt[i]--;
                bool b=dfs(p^1,cursum+i);
                cnt[i]++;
                return !b;
            }
            return false;
        }
    }
public:
    //模拟题，当第一步拿走 1 或者拿走 2 的时候，后续的拿法已经被确定，所以直接模拟就可以过
    //有一点就是：拿0等于拖延时间，不会改变当前状态，所以，如果同时能拿 {0,x}，拿0和拿x没有区别
    bool stoneGameIX(vector<int>& stones) {
        for(int a:stones)cnt[a%3]++;
        return dfs(0,0);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<int>stones{1,2,1,2,3};
    auto ans=sol.stoneGameIX(stones);
    DBG(ans);

    system("pause");
    return 0;
}