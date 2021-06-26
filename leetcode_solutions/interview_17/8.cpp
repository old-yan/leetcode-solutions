#include "SegTree.h"
#include "utils.h"

SegTree<int>T(10000,[](int x,int y){return max(x,y);});
class Solution {
public:
    int bestSeqAtIndex(vector<int>& height, vector<int>& weight) {
        vector<pair<int,int>>hw;
        int n=height.size();
        hw.reserve(n);
        REP(i,n)hw.emplace_back(height[i],-weight[i]);
        sort(ALL(hw));
        T.set(0);
        for(auto [h,w]:hw){
            T.step(-w,T(0,-w-1)+1);
        }
        return T.data[1];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi height{65,70,56,75,60,68};
    vi weight{100,150,90,190,95,110};
    auto ans=sol.bestSeqAtIndex(height,weight);
    DBG(ans);

    system("pause");
    return 0;
}
