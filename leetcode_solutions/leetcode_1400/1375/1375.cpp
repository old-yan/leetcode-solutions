#include "SegTree.h"
#include "utils.h"

SegTree<int>T(40001,[](int x,int y){return x+y;});
class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
        T.set(0);
        int ans=0;
        REP(i,light.size()){
            T.set(light[i],1);
            if(T(1,i+1)==i+1)ans++;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi light{2,1,3,5,4};
    auto ans=sol.numTimesAllBlue(light);
    DBG(ans);

    system("pause");
    return 0;
}
