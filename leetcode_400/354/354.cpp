#include "SegTree.h"
#include "utils.h"

SegTree<int>T(5001,[](int x,int y){return max(x,y);});
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(ALL(envelopes),[](vi&x,vi&y){
            if(x[0]!=y[0])return x[0]>y[0];
            return x[1]<y[1];
        });
        vi h;
        for(auto&envelope:envelopes)h.pb(envelope[1]);
        vi rnk=getrank2(h);
        T.set(0);
        for(int r:rnk){
            T.set(r,T(r+1,rnk.size()-1)+1);
        }
        return T.data[1];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi envelopes{
        {5,4},{6,4},{6,7},{2,3}
    };
    auto ans=sol.maxEnvelopes(envelopes);
    DBG(ans);

    system("pause");
    return 0;
}
