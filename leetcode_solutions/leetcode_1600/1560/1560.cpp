#include "utils.h"

class Solution {
public:
    vector<int> mostVisited(int n, vector<int>& rounds) {
        vi ans;
        int idx=rounds[0]-1;
        while(true){
            ans.pb(idx+1);
            if(idx==rounds.back()-1)break;
            idx=(idx+1)%n;
        }
        sort(ALL(ans));
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=4;
    vi rounds{1,3,1,2};
    auto ans=sol.mostVisited(n,rounds);
    DBGV(ans);

    system("pause");
    return 0;
}
