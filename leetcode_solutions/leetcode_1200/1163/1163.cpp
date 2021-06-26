#include "utils.h"

class Solution {
public:
    string lastSubstring(const string&s) {
        int i=0,j=1,k;
        while(i<s.size()&&j<s.size()){
            for(k=0;s[i+k]==s[j+k];k++);
            if(s[i+k]<s[j+k])i+=k+1;
            else j+=k+1;
            if(i==j)i++;
        }
        return s.substr(min(i,j));
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="leetcode";
    auto ans=sol.lastSubstring(s);
    DBG(ans);

    system("pause");
    return 0;
}
