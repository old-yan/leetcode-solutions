#include "utils.h"

class Solution {
public:
    //暴力模拟是可以过的，但是可以将时间复杂度压缩到线性
    //首先，求出差分数组；
    //然后，还原数组，找出最大值处。
    int maximumPopulation(vector<vector<int>>& logs) {
        int cnt[3000]={0};
        for(auto&l:logs){
            //出生年人数加一
            cnt[l[0]]++;
            //去世年人数减一
            cnt[l[1]]--;
        }
        //前缀和
        partial_sum(cnt,cnt+3000,cnt);
        return max_element(cnt,cnt+3000)-cnt;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi logs=makevvi("[[1993,1999],[2000,2010]]");
    auto ans=sol.maximumPopulation(logs);
    DBG(ans);

    system("pause");
    return 0;
}
