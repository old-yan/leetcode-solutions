#include "utils.h"

class Solution {
public:
    int minInsertions(string s) {
        int left=0,ans=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                left++;
            }
            else{
                if(s[i+1]!=')')ans++;
                else i++;
                if(!left)ans++;
                else left--;
            }
        }
        return ans+left*2;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="))())(";
    auto ans=sol.minInsertions(s);
    DBG(ans);

    system("pause");
    return 0;
}
