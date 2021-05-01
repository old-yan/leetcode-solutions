#include "utils.h"

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        vi presum=cardPoints;
        partial_sum(ALL(presum),presum.begin());
        vi postsum=cardPoints;
        partial_sum(ALLR(postsum),postsum.rbegin());
        int ans=max(presum[k-1],postsum[cardPoints.size()-k]);
        REP(i,k-1){
            chmax(ans,presum[i]+postsum[cardPoints.size()-k+i+1]);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi cardPoints{1,2,3,4,5,6,1};
    int k=3;
    auto ans=sol.maxScore(cardPoints,k);
    DBG(ans);

    system("pause");
    return 0;
}
