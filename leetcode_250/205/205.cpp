#include "utils.h"

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char>M;
        unordered_map<char,char>M2;
        REP(i,s.size()){
            if(M.count(s[i])&&M[s[i]]!=t[i])return false;
            if(M2.count(t[i])&&M2[t[i]]!=s[i])return false;
            M[s[i]]=t[i];
            M2[t[i]]=s[i];
        }
        return true;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="egg";
    string t="add";
    auto ans=sol.isIsomorphic(s,t);
    DBG(ans);

    system("pause");
    return 0;
}
