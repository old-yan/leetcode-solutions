#include "utils.h"

class Solution {
public:
    int maxPower(string s) {
        auto next=next_different(s);
        int ans=1;
        for(int i=0;i<next.size();i=next[i]){
            chmax(ans,next[i]-i);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="leetcode";
    auto ans=sol.maxPower(s);
    DBG(ans);

    system("pause");
    return 0;
}
