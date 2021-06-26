#include "utils.h"

class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        sort(ALL(s1));
        sort(ALL(s2));
        int a=0,b=0;
        REP(i,s1.size()){
            if(s1[i]<s2[i])a++;
            else if(s1[i]>s2[i])b++;
        }
        return !a||!b;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s1="abc";
    string s2="xya";
    auto ans=sol.checkIfCanBreak(s1,s2);
    DBG(ans);

    system("pause");
    return 0;
}
