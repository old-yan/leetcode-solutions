#include "utils.h"

class Solution {
    int mark[128];
    int appear[32];
    void init(){
        memset(mark,0xff,sizeof(mark));
        mark['a']=0;
        mark['e']=1;
        mark['i']=2;
        mark['o']=3;
        mark['u']=4;
    }
public:
    int findTheLongestSubstring(string s) {
        init();
        memset(appear,0x3f,sizeof(appear));
        appear[0]=-1;
        int mask=0,ans=0;
        REP(i,s.size()){
            if(mark[s[i]]>=0){
                mask^=1<<mark[s[i]];
            }
            chmax(ans,int(i)-appear[mask]);
            chmin(appear[mask],int(i));
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="eleetminicoworoep";
    auto ans=sol.findTheLongestSubstring(s);
    DBG(ans);

    system("pause");
    return 0;
}
