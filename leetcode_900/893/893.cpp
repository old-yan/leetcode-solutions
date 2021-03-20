#include "utils.h"

class Solution {
public:
    int numSpecialEquivGroups(vector<string>& A) {
        for(string&s:A){
            vector<char>v;
            for(int i=0;i<s.size();i+=2)v.pb(s[i]);
            sort(ALL(v));
            for(int i=0;i<s.size();i+=2)s[i]=v[i/2];
            v.clear();
            for(int i=1;i<s.size();i+=2)v.pb(s[i]);
            sort(ALL(v));
            for(int i=1;i<s.size();i+=2)s[i]=v[i/2];
        }
        sort(ALL(A));
        return unique(ALL(A))-A.begin();
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<string>A{"abc","acb","bac","bca","cab","cba"};
    auto ans=sol.numSpecialEquivGroups(A);
    DBG(ans);

    system("pause");
    return 0;
}
