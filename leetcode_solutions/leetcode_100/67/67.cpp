#include "utils.h"

class Solution {
public:
    string addBinary(string a, string b) {
        int aa[10001]={0},bb[10001]={0};
        REP(i,a.size())aa[a.size()-1-i]=a[i]-'0';
        REP(i,b.size())bb[b.size()-1-i]=b[i]-'0';
        int jinwei=0,maxdigit=0;
        REP(i,max(a.size(),b.size())+1){
            aa[i]+=bb[i]+jinwei;
            jinwei=aa[i]>1;
            aa[i]%=2;
            if(aa[i]){
                chmax(maxdigit,int(i));
            }
        }
        string ans;
        REPR(i,maxdigit){
            ans+='0'+aa[i];
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string a="1010";
    string b="1011";
    auto ans=sol.addBinary(a,b);
    DBG(ans);

    system("pause");
    return 0;
}
