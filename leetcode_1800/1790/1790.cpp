#include "utils.h"

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n=s1.size();
        vi dif;
        REP(i,n){
            if(s1[i]!=s2[i]){
                dif.pb(i);
            }
        }
        if(dif.size()>2||dif.size()==1)return false;
        if(dif.empty())return true;
        return s1[dif[0]]==s2[dif[1]]&&s1[dif[1]]==s2[dif[0]];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s1="bank";
    string s2="kanb";
    auto ans=sol.areAlmostEqual(s1,s2);
    DBG(ans);

    system("pause");
    return 0;
}
