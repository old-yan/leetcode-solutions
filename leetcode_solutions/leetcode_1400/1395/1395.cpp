#include "SegTree.h"
#include "utils.h"

SegTree<int>T(100000,[](int x,int y){return x+y;});
class Solution {
    int leftSmaller[1000],rightSmaller[1000],leftBigger[1000],rightBigger[1000];
public:
    int numTeams(vector<int>& rating) {
        int n=rating.size();
        int Max=*max_element(ALL(rating));
        for(T.X=4;T.X<=Max;T.X<<=1);
        T.set(0);
        REP(i,n){
            leftSmaller[i]=T(0,rating[i]-1);
            leftBigger[i]=T(rating[i]+1,100000);
            T.step_forward(rating[i]);
        }
        ll ans=0;
        T.set(0);
        REPR(i,n-1){
            ans+=T(0,rating[i]-1)*leftBigger[i];
            ans+=T(rating[i]+1,100000)*leftSmaller[i];
            T.step_forward(rating[i]);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi rating{2,5,3,4,1};
    auto ans=sol.numTeams(rating);
    DBG(ans);

    system("pause");
    return 0;
}
