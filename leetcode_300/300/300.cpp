#include "utils.h"

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vi v=getrank2(nums);
        zkwMaxTree T;
        int ans=0;
        REP(i,v.size()){
            int len=1;
            if(v[i])chmax(len,T(0,v[i]-1)+1);
            chmax(ans,len);
            if(T[v[i]]<len)T.set(v[i],len);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{11,12,13,14,15,6,7,8,101,18};
    auto ans=sol.lengthOfLIS(nums);
    DBG(ans);

    system("pause");
    return 0;
}
