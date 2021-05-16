#include "utils.h"

class Solution {
public:
    int minimumDeletions(string s) {
        int n=s.size();
        int acount[n+1];
        acount[0]=0;
        REP(i,n)acount[i+1]=acount[i]+(s[i]=='a');
        int ans=INT_MAX;
        REP(i,n+1){
            chmin(ans,int(i)+acount[n]-acount[i]*2);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="aababbab";
    auto ans=sol.minimumDeletions(s);
    DBG(ans);

    system("pause");
    return 0;
}
