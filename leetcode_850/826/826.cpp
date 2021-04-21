#include "utils.h"

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vi p(max(*max_element(ALL(difficulty)),*max_element(ALL(worker)))+1,0);
        REP(i,difficulty.size()){
            chmax(p[difficulty[i]],profit[i]);
        }
        partial_sum(ALL(p),p.begin(),[](int x,int y){return max(x,y);});
        int ans=0;
        for(int w:worker){
            ans+=p[w];
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
