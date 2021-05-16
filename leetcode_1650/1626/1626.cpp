#include "SegTree.h"
#include "utils.h"

SegTree<int>T(1001,[](int x,int y){return max(x,y);});
class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n=scores.size();
        vi idxes(n);
        iota(ALL(idxes),0);
        sort(ALL(idxes),[&](int x,int y){return scores[x]<scores[y]||(scores[x]==scores[y]&&ages[x]<ages[y]);});
        T.set(0);
        for(auto idx:idxes){
            int score=scores[idx],age=ages[idx];
            T.step(age,T(0,age)+score);
        }
        return T.data[1];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi scores{1,3,5,10,15};
    vi ages{1,2,3,4,5};
    auto ans=sol.bestTeamScore(scores,ages);
    DBG(ans);

    system("pause");
    return 0;
}
