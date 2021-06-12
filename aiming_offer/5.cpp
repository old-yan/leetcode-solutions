#include "utils.h"

class Solution {
public:
    string replaceSpace(string s) {
        string ans;
        for(char c:s){
            if(c==' '){
                ans+="%20";
            }
            else ans+=c;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="We are happy.";
    auto ans=sol.replaceSpace(s);
    DBG(ans);

    system("pause");
    return 0;
}
