#include "SegTree.h"
#include "utils.h"

SegTree<int>T(10101,[](int x,int y){return min(x,y);});
class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        T.set(1000000);
        T.set(0,0);
        vector<pair<int,int>>v;
        REP(i,n+1)v.emplace_back(i-ranges[i],i+ranges[i]);
        sort(ALL(v),[](pair<int,int>&x,pair<int,int>&y){return x.second<y.second;});
        for(auto [l,r]:v){
            T.step(r,T(l,r)+1);
        }
        int ans=T(n,n+100);
        if(ans<1000000)return ans;
        else return -1;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=5;
    vi ranges{3,4,1,1,0,0};
    auto ans=sol.minTaps(n,ranges);
    DBG(ans);

    system("pause");
    return 0;
}
