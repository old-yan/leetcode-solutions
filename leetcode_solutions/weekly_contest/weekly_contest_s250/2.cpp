#include "utils.h"

class Solution {
public:
    int addRungs(vector<int>& rungs, int dist) {
        int ans=0,cur=0;
        for(int a:rungs){
            ans+=(a-cur-1)/dist;
            cur=a;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi rungs{1,3,5,10};
    int dist=2;
    auto ans=sol.addRungs(rungs,dist);
    DBG(ans);

    system("pause");
    return 0;
}
