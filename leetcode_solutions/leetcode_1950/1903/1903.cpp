#include "utils.h"

class Solution {
public:
    string largestOddNumber(string num) {
        int ans=-1;
        REP(i,num.size()){
            if((num[i]-'0')%2){
                ans=i;
            }
        }
        if(ans<0)return "";
        else return num.substr(ans+1);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string num="52";
    auto ans=sol.largestOddNumber(num);
    DBG(ans);

    system("pause");
    return 0;
}
