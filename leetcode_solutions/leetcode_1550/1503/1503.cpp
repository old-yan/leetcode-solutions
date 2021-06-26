#include "utils.h"

class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int ans=0;
        for(int a:left)chmax(ans,a);
        for(int a:right)chmax(ans,n-a);
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=4;
    vi left{4,3};
    vi right{0,1};
    auto ans=sol.getLastMoment(n,left,right);
    DBG(ans);

    system("pause");
    return 0;
}
