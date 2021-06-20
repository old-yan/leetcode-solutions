#include "utils.h"

class Solution {
public:
    //由于本题数据没有前导零，所以只要尾数字为奇数，长度尽量长就行。
    string largestOddNumber(string num) {
        int anslen=0;
        for(int i=0;i<num.size();i++){
            if((num[i]-'0')%2){
                anslen=i+1;
            }
        }
        return num.substr(0,anslen);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string num="35427";
    auto ans=sol.largestOddNumber(num);
    DBG(ans);

    system("pause");
    return 0;
}
