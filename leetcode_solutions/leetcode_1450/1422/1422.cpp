#include "utils.h"

class Solution {
public:
    int maxScore(string s) {
        vi original;
        REP(i,s.size())original.pb(s[i]-'0');
        auto left_ones=original;
        partial_sum(ALL(left_ones),left_ones.begin());
        auto right_ones=original;
        partial_sum(ALLR(right_ones),right_ones.rbegin());
        int ans=INT_MIN;
        FOR(i,1,s.size()){
            chmax(ans,int(i)-left_ones[i-1]+right_ones[i]);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="011101";
    auto ans=sol.maxScore(s);
    DBG(ans);

    system("pause");
    return 0;
}
