#include "utils.h"

class Solution {
    bool check(string&a,string&b){
        auto arm=getarm(b);
        bool flag=true;
        REP(i,a.size()/2){
            if(query_polindromic(arm,i,b.size()-1-i))return true;
            if(a[i]!=b[b.size()-1-i]){
                flag=false;
                break;
            }
        }
        if(flag)return true;
        flag=true;
        REP(i,a.size()/2){
            if(query_polindromic(arm,i,b.size()-1-i))return true;
            if(a[a.size()-1-i]!=b[i]){
                flag=false;
                break;
            }
        }
        return flag;
    }
public:
    bool checkPalindromeFormation(string a, string b) {
        return check(a,b)||check(b,a);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string a="abdef";
    string b="fecab";
    auto ans=sol.checkPalindromeFormation(a,b);
    DBG(ans);

    system("pause");
    return 0;
}
