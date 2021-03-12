#include "SegTree.h"
#include "utils.h"

class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        SegTree<int>T(121,0,[](int x,int y){return x+y;});
        for(int age:ages)T.step_forward(age);
        int ans=0;
        for(int age:ages){
            int left=age/2+8;
            int right=age;
            ans+=T(left,right);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi ages{20,30,100,110,120};
    auto ans=sol.numFriendRequests(ages);
    DBG(ans);

    system("pause");
    return 0;
}
