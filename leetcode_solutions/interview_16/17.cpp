#include "SegTree.h"
#include "utils.h"

struct node{
    ll all,left,right,max;
    node():all(0),left(INT_MIN),right(INT_MIN),max(INT_MIN){}
    node(ll val):all(val),left(val),right(val),max(val){}
    node(ll _all,ll _left,ll _right,ll _max):all(_all),left(_left),right(_right),max(_max){}
    node operator+(const node&other)const{
        return {all+other.all, ::max(left,all+other.left), ::max(other.right,right+other.all), ::max({max,other.max,right+other.left})};
    }
};

SegTree<node>T(10,[](const node&x,const node&y){return x+y;});
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        T.set(nums);
        return T.data[1].max;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{-1};
    auto ans=sol.maxSubArray(nums);
    DBG(ans);

    system("pause");
    return 0;
}
