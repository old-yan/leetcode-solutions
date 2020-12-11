#include "utils.h"

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int minlen=100000;
        for(string&s:strs)chmin(minlen,int(s.size()));
        REP(i,minlen){
            set<char>S;
            for(string&s:strs){
                S.insert(s[i]);
            }
            if(S.size()>1)return strs[0].substr(0,i);
        }
        return strs[0].substr(0,minlen);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<string>strs{"flower","flow","flight"};
    auto ans=sol.longestCommonPrefix(strs);
    DBG(ans);

    system("pause");
    return 0;
}
