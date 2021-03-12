#include "utils.h"

class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        bitset<2001>ban;
        bitset<2001>appear;
        int cnt[2001]={0};
        REP(i,fronts.size()){
            int a=fronts[i],b=backs[i];
            if(a==b)ban.set(a);
            appear.set(a);
            appear.set(b);
        }
        for(int i=appear._Find_first();i<appear.size();i=appear._Find_next(i)){
            if(!ban[i])return i;
        }
        return 0;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi fronts{1,2,4,4,7};
    vi backs{1,3,4,1,3};
    auto ans=sol.flipgame(fronts,backs);
    DBG(ans);

    system("pause");
    return 0;
}
