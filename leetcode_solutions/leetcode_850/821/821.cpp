#include "utils.h"

class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vi ans(s.size(),INT_MAX);
        REP(i,s.size()){
            int j=s.find_first_of(c,i);
            if(j>=0)chmin(ans[i],int(abs(j-i)));
            int k=s.find_last_of(c,i);
            if(k>=0)chmin(ans[i],int(abs(k-i)));
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="loveleetcode";
    char c='e';
    auto ans=sol.shortestToChar(s,c);
    DBGV(ans);

    system("pause");
    return 0;
}
