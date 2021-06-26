#include "utils.h"

class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        auto next=next_different(s);
        vvi ans;
        for(int i=0;i<s.size();i=next[i]){
            if(next[i]>=i+3){
                ans.pb({i,next[i]-1});
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="abbxxxxyyz";
    auto ans=sol.largeGroupPositions(s);
    DBGVV(ans);

    system("pause");
    return 0;
}
