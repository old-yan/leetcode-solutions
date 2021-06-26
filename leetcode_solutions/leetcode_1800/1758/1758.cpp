#include "utils.h"

class Solution {
public:
    int minOperations(string s) {
        int odd_zero=0,odd_one=0,even_zero=0,even_one=0;
        REP(i,s.size()){
            if(i%2==0){
                even_zero+=s[i]=='0';
                even_one+=s[i]=='1';
            }
            else{
                odd_zero+=s[i]=='0';
                odd_one+=s[i]=='1';
            }
        }
        return min(even_zero+odd_one,even_one+odd_zero);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="0100";
    auto ans=sol.minOperations(s);
    DBG(ans);

    system("pause");
    return 0;
}
