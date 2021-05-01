#include "utils.h"

class Solution {
public:
    string sortString(string s) {
        int cnt[26]={0};
        for(char c:s)cnt[c-'a']++;
        string ans;
        while(ans.size()<s.size()){
            REP(i,26)if(cnt[i]){
                cnt[i]--;
                ans+='a'+i;
            }
            REPR(i,25)if(cnt[i]){
                cnt[i]--;
                ans+='a'+i;
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="aaaabbbbcccc";
    auto ans=sol.sortString(s);
    DBG(ans);

    system("pause");
    return 0;
}
