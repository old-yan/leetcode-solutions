#include "utils.h"

class Solution {
public:
    int findSubstringInWraproundString(string p) {
        int maxlead[26]={0};
        for(int i=0,j;i<p.size();){
            for(j=i+1;j<p.size()&&(p[j]+25-p[j-1])%26==0;j++);
            while(i<j){
                chmax(maxlead[p[i]-'a'],j-i);
                i++;
            }
        }
        int ans=0;
        REP(i,26)ans+=maxlead[i];
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string p="zab";
    auto ans=sol.findSubstringInWraproundString(p);
    DBG(ans);

    system("pause");
    return 0;
}
