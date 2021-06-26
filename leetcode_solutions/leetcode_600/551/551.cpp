#include "utils.h"

class Solution {
public:
    bool checkRecord(string s) {
        bool haveA=false;
        REP(i,s.size()){
            if(s[i]=='A'){
                if(haveA)return false;
                else haveA=true;
            }
            else if(s[i]=='L'){
                if(i>1&&s[i-1]=='L'&&s[i-2]=='L')return false;
            }
        }
        return true;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="PPALLP";
    auto ans=sol.checkRecord(s);
    DBG(ans);

    system("pause");
    return 0;
}
