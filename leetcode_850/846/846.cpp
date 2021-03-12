#include "utils.h"

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        map<int,int>M;
        for(int a:hand)M[a]++;
        while(M.size()){
            map<int,int>::iterator it[W];
            it[0]=M.begin();
            FOR(i,1,W){
                it[i]=next(it[i-1]);
                if(it[i]==M.end()||it[i]->first!=it[i-1]->first+1)return false;
            }
            REPR(i,W-1){
                if(!--it[i]->second)M.erase(it[i]);
            }
        }
        return true;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi hand{1,2,3,6,2,3,4,7,8};
    int W=3;
    auto ans=sol.isNStraightHand(hand,W);
    DBG(ans);

    system("pause");
    return 0;
}
