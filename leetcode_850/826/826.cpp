#include "SegTree.h"
#include "utils.h"

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        SegTree<int>T(100000,0,[](int x,int y){return max(x,y);});
        REP(i,difficulty.size()){
            T.step(difficulty[i],profit[i]);
        }
        int ans=0;
        for(int w:worker){
            ans+=T(0,w);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi difficulty{2,4,6,8,10};
    vi profit{10,20,30,40,50};
    vi worker{4,5,6,7};
    auto ans=sol.maxProfitAssignment(difficulty,profit,worker);
    DBG(ans);

    system("pause");
    return 0;
}
