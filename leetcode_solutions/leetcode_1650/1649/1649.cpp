#include "SegTree.h"
#include "utils.h"

SegTree<int>T(100000,[](int x,int y){return x+y;});
class Solution {
public:
    int createSortedArray(vector<int>& instructions) {
        T.set(0);
        ll ans=0;
        for(int a:instructions){
            int smaller=T(0,a-1);
            int bigger=T(a+1,100000);
            ans+=min(smaller,bigger);
            T.step_forward(a);
        }
        return ans%MOD;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi instructions{1,5,6,2};
    auto ans=sol.createSortedArray(instructions);
    DBG(ans);

    system("pause");
    return 0;
}
