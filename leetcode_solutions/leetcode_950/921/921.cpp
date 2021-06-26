#include "utils.h"

class Solution {
public:
    int minAddToMakeValid(string S) {
        int left=0,ans=0;
        for(char c:S){
            if(c=='('){
                left++;
            }
            else{
                if(left)left--;
                else ans++;
            }
        }
        return left+ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string S="()))((";
    auto ans=sol.minAddToMakeValid(S);
    DBG(ans);

    system("pause");
    return 0;
}
