#include "utils.h"

class Solution {
public:
    //不断地找数组里的最大值，然后把最大值和最大值的一半拿走，重复这个过程
    vector<int> findOriginalArray(vector<int>& changed) {
        //先排除奇数长度的数组
        if(changed.size()%2==1)return {};
        //将数组统计到cnt里
        int cnt[100001]={0};
        for(int a:changed)cnt[a]++;
        vector<int>ans;
        //从大往小扫描，每次扫描到当前最大数，就取走它和它的一半
        for(int val=100000;val>0;val--){
            int num=cnt[val];
            //如果是奇数，说明无解
            if(num!=0&&val%2==1)return {};
            //如果没有一半，说明无解
            if(cnt[val/2]<num)return {};
            cnt[val/2]-=num;
            ans.insert(ans.end(),num,val/2);
        }
        ans.insert(ans.end(),cnt[0]/2,0);
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi changed{1,3,4,2,6,8};
    auto ans=sol.findOriginalArray(changed);
    DBGV(ans);

    system("pause");
    return 0;
}