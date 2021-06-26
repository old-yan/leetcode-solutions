#include "utils.h"

class Solution {
public:
    bool isUnique(string astr) {
        for(char c:astr){
            int cnt=0;
            for(char d:astr)cnt+=c==d;
            if(cnt>1)return false;
        }
        return true;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string astr="leetcode";
    auto ans=sol.isUnique(astr);
    DBG(ans);

    system("pause");
    return 0;
}
