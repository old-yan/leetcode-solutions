#include "utils.h"

class Solution {
public:
    int minDeletions(string s) {
        int cnt[26]={0};
        for(char c:s)cnt[c-'a']++;
        priority_queue<int>Q;
        REP(i,26)if(cnt[i])Q.push(cnt[i]);
        int pre=INT_MAX;
        int ans=0;
        while(Q.size()){
            auto p=Q.top();
            Q.pop();
            if(!pre)ans+=p;
            else if(p>=pre){
                ans+=p-pre+1;
                pre--;
            }
            else{
                pre=p;
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="aaabbbcc";
    auto ans=sol.minDeletions(s);
    DBG(ans);

    system("pause");
    return 0;
}
