#include "utils.h"

class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        ll dp[220000]={1,-1};
        int cur=0;
        for(int i=0;i<s.size();i++){
            cur+=dp[i];
            if(s[i]=='0'&&cur){
                dp[i+minJump]++;
                dp[i+maxJump+1]--;
            }
        }
        return s.back()=='0'&&cur;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="011010";
    int minJump=2;
    int maxJump=3;
    auto ans=sol.canReach(s,minJump,maxJump);
    DBG(ans);

    system("pause");
    return 0;
}
