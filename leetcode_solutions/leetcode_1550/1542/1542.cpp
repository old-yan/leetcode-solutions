#include "utils.h"

class Solution {
public:
    int longestAwesome(string s) {
        int mask=0;
        int first[1<<10];
        memset(first,0x3f,sizeof(first));
        first[0]=-1;
        int ans=0;
        REP(i,s.size()){
            mask^=1<<(s[i]-'0');
            chmax(ans,int(i-first[mask]));
            chmin(first[mask],int(i));
            REP(j,10){
                chmax(ans,int(i-first[mask^(1<<j)]));
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="3242415";
    auto ans=sol.longestAwesome(s);
    DBG(ans);

    system("pause");
    return 0;
}
