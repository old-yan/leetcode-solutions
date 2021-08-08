#include "utils.h"

class Solution {
public:
    //最简单的贪心思想，遇到左括号left++，遇到右括号，能抵消左括号就left--，不能抵消那就去右侧找个左括号进行swap
    int minSwaps(string s) {
        int left=0;
        int ans=0;
        for(char c:s){
            if(c=='[')left++;
            else if(left)left--;
            else left++,ans++;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="]]][[[";
    auto ans=sol.minSwaps(s);
    DBG(ans);

    system("pause");
    return 0;
}
