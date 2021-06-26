#include "utils.h"

class Solution {
public:
    int minFlips(string s) {
        int n=s.size(),ans=0x3f3f3f3f;
        if(n%2==0){
            string t;
            REP(i,n)t+=char('0'+i%2);
            int cnt=0;
            REP(i,n)cnt+=s[i]!=t[i];
            return min(cnt,n-cnt);
        }
        else{
            string t1,t2;
            REP(i,n){
                t1+=char('0'+i%2);
                t2+=char('0'+(i+1)%2);
            }
            int pre1[n],post2[n+1];
            REP(i,n){
                pre1[i]=i?pre1[i-1]+(s[i]!=t1[i]):s[i]!=t1[i];
            }
            post2[n]=0;
            REPR(i,n-1){
                post2[i]=post2[i+1]+(s[i]!=t2[i]);
            }
            int ans=INT_MAX;
            REP(i,n){
                chmin(ans,pre1[i]+post2[i+1]);
                chmin(ans,n-pre1[i]-post2[i+1]);
            }
            return ans;
        }
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="11101";
    auto ans=sol.minFlips(s);
    DBG(ans);

    system("pause");
    return 0;
}
