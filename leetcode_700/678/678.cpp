#include "utils.h"

class Solution {
public:
    bool checkValidString(string s) {
        if(s.empty())return true;
        int Max[s.size()],Min[s.size()];
        #define a(i) (i>=0?Max[i]:0)
        #define b(i) (i>=0?Min[i]:0)
        REP(i,s.size()){
            if(s[i]=='('){
                Max[i]=a(i-1)+1;
                Min[i]=b(i-1)+1;
            }
            else if(s[i]==')'){
                Max[i]=a(i-1)-1;
                Min[i]=max(0,b(i-1)-1);
            }
            else{
                Max[i]=a(i-1)+1;
                Min[i]=max(0,b(i-1)-1);
            }
            if(Max[i]<0)return false;
        }
        return Min[s.size()-1]==0;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="(*))";
    auto ans=sol.checkValidString(s);
    DBG(ans);

    system("pause");
    return 0;
}
