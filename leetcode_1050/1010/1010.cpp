#include "utils.h"

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int cnt[60]={0};
        ll ans=0;
        for(int t:time){
            ans+=cnt[(600-t)%60];
            cnt[t%60]++;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi time{30,20,150,100,40};
    auto ans=sol.numPairsDivisibleBy60(time);
    DBG(ans);

    system("pause");
    return 0;
}
