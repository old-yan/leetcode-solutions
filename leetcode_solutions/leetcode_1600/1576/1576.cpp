#include "utils.h"

class Solution {
public:
    string modifyString(string s) {
        REP(i,s.size()){
            if(s[i]=='?'){
                REP(c,26){
                    if(!i||s[i-1]!='a'+c){
                        if(s[i+1]!='a'+c){
                            s[i]='a'+c;
                            break;
                        }
                    }
                }
            }
        }
        return s;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="??yw?ipkj?";
    auto ans=sol.modifyString(s);
    DBG(ans);

    system("pause");
    return 0;
}
