#include "utils.h"

class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string ans(s.size(),' ');
        REP(i,s.size())ans[indices[i]]=s[i];
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="codeleet";
    vi indices{4,5,6,7,0,2,1,3};
    auto ans=sol.restoreString(s,indices);
    DBG(ans);

    system("pause");
    return 0;
}
