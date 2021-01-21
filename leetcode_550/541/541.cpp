#include "utils.h"

class Solution {
public:
    string reverseStr(string s, int k) {
        int i;
        for(i=0;i+k<=s.size();i+=k*2){
            reverse(&s[0]+i,&s[0]+i+k);
        }
        if(i<s.size())reverse(&s[0]+i,&s[0]+s.size());
        return s;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="abcdefg";
    int k=2;
    auto ans=sol.reverseStr(s,k);
    DBG(ans);

    system("pause");
    return 0;
}
