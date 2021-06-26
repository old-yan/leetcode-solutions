#include "utils.h"

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int cnt[26]={0};
        for(char c:text)cnt[c-'a']++;
        int ans=INT_MAX;
        chmin(ans,cnt['a'-'a']);
        chmin(ans,cnt['b'-'a']);
        chmin(ans,cnt['l'-'a']/2);
        chmin(ans,cnt['o'-'a']/2);
        chmin(ans,cnt['n'-'a']);
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string text="nlaebolko";
    auto ans=sol.maxNumberOfBalloons(text);
    DBG(ans);

    system("pause");
    return 0;
}
