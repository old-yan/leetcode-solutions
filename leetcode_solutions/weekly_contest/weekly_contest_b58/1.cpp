#include "utils.h"

class Solution {
public:
    //简单模拟
    string makeFancyString(string s) {
        string ans;
        for(char c:s){
            if(ans.size()>=2&&c==ans.back()&&c==ans[ans.size()-2])continue;
            ans+=c;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="leeetcode";
    auto ans=sol.makeFancyString(s);
    DBG(ans);

    system("pause");
    return 0;
}
