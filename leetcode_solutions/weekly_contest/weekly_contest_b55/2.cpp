#include "utils.h"

class Solution {
public:
    //暴力模拟即可。也可以用栈来优化
    string removeOccurrences(string s, string part) {
        string ans;
        for(char c:s){
            ans+=c;
            if(ans.size()>=part.size()&&memcmp(&ans[ans.size()-part.size()],&part[0],part.size())==0){
                for(int i=0;i<part.size();i++)ans.pop_back();
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="axxxxyyyyb";
    string part="xy";
    auto ans=sol.removeOccurrences(s);
    DBG(ans);

    system("pause");
    return 0;
}
