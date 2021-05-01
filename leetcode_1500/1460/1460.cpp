#include "utils.h"

class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        int cnt[1001]={0};
        for(int a:target)cnt[a]++;
        for(int a:arr)cnt[a]--;
        FOR(i,1,1001)if(cnt[i])return false;
        return true;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi target{1,2,3,4};
    vi arr{2,3,4,1};
    auto ans=sol.canBeEqual(target,arr);
    DBG(ans);

    system("pause");
    return 0;
}
