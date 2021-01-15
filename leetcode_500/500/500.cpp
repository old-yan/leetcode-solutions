#include "utils.h"

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        string s1="qwertyuiopQWERTYUIOP";
        string s2="asdfghjklASDFGHJKL";
        string s3="zxcvbnmZXCVBNM";
        Union u(128);
        REP(i,s1.size()-1)u.unite(s1[i],s1[i+1]);
        REP(i,s2.size()-1)u.unite(s2[i],s2[i+1]);
        REP(i,s3.size()-1)u.unite(s3[i],s3[i+1]);
        vector<string>ans;
        for(string&s:words){
            unordered_set<int>S;
            for(char c:s)S.insert(u.Find(c));
            if(S.size()<=1)ans.pb(s);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<string>words{"Hello", "Alaska", "Dad", "Peace"};
    auto ans=sol.findWords(words);
    DBGV(ans);

    system("pause");
    return 0;
}
