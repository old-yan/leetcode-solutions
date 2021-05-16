#include "utils.h"

class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        int n=aliceValues.size();
        vi idxes(n);
        iota(ALL(idxes),0);
        sort(ALL(idxes),[&](int x,int y){return aliceValues[x]+bobValues[x]>aliceValues[y]+bobValues[y];});
        int value=0;
        for(int i=0;i<n;i+=2)value+=aliceValues[idxes[i]];
        for(int i=1;i<n;i+=2)value-=bobValues[idxes[i]];
        if(value>0)return 1;
        else if(value<0)return -1;
        else return 0;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi aliceValues{1,3};
    vi bobValues{2,1};
    auto ans=sol.stoneGameVI(aliceValues,bobValues);
    DBG(ans);

    system("pause");
    return 0;
}
