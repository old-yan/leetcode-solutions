#include "utils.h"

class Solution {
public:
    int maxDepth(string s) {
        int ans=0,cur=0;
        for(char c:s){
            if(c=='(')cur++;
            else if(c==')')cur--;
            chmax(ans,cur);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="(1+(2*3)+((8)/4))+1";
    auto ans=sol.maxDepth(s);
    DBG(ans);

    system("pause");
    return 0;
}
