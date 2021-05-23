#include "utils.h"

class Solution {
    string s;
    bool dfs(int i,ll pre,int cnt){
        if(i==s.size()){
            return cnt>1;
        }
        else{
            ll val=0;
            FOR(j,i,s.size()){
                val=val*10+s[j]-'0';
                if(val>0x3f3f3f3f3f3f3f)break;
                if(pre<0||val==pre+1||val==pre-1){
                    if(dfs(j+1,val,cnt+1)){
                        return true;
                    }
                }
            }
            return false;
        }
    }
public:
    bool splitString(string _s) {
        s=_s;
        return dfs(0,-1,0);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="1234";
    auto ans=sol.splitString(s);
    DBG(ans);

    system("pause");
    return 0;
}
