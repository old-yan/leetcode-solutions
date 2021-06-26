#include "SegTree.h"
#include "utils.h"

SegTree<int>T(121,[](int x,int y){return x+y;});
class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        vi cnt(121,0);
        for(int age:ages)cnt[age]++;
        T.set(cnt);
        int ans=0;
        for(int age=1;age<=120;age++){
            if(!cnt[age])continue;
            int res=T(age/2+8,age);
            if(res)ans+=(res-1)*cnt[age];
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi ages{20,30,100,110,120};
    auto ans=sol.numFriendRequests(ages);
    DBG(ans);

    system("pause");
    return 0;
}
