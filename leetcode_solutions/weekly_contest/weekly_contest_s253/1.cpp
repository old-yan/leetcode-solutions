#include "utils.h"

class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        string cur;
        for(auto&a:words){
            cur+=a;
            if(cur==s)return true;
        }
        return false;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="iloveleetcode";
    vector<string>words{"i","love","leetcode","apples"};
    auto ans=sol.isPrefixString(s,words);
    DBG(ans);

    system("pause");
    return 0;
}
