#include "utils.h"

class Solution {
public:
    string maskPII(string S) {
        if(int(S.find('@'))>=0){
            for(char&c:S)c=tolower(c);
            int i=S.find('@');
            return S.substr(0,1)+"*****"+S[i-1]+S.substr(i);
        }
        else{
            S.erase(remove(ALL(S),' '),S.end());
            S.erase(remove(ALL(S),'('),S.end());
            S.erase(remove(ALL(S),')'),S.end());
            S.erase(remove(ALL(S),'+'),S.end());
            S.erase(remove(ALL(S),'-'),S.end());
            for(int i=0;i<3;i++)S[i]='*';
            if(S.size()==10){
                return "***-***-"+S.substr(6);
            }
            else{
                int extra=S.size()-10;
                return "+"+S.substr(0,extra)+"-***-***-"+S.substr(extra+6);
            }
        }
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string S="LeetCode@LeetCode.com";
    auto ans=sol.maskPII(S);
    DBG(ans);

    system("pause");
    return 0;
}
