#include "utils.h"

class Solution {
public:
    bool checkZeroOnes(string s) {
        int one=0,zero=0;
        for(int i=0,j;i<s.size();i=j){
            for(j=i+1;s[j]==s[i];j++);
            if(s[i]=='1')one=max(one,j-i);
            else zero=max(zero,j-i);
        }
        return one>zero;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="1101";
    auto ans=sol.checkZeroOnes(s);
    DBG(ans);

    system("pause");
    return 0;
}
