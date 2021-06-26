#include "utils.h"

class Solution {
public:
    int minSwaps(string s) {
        int cnt[2][2]={0};
        REP(i,s.size()){
            cnt[i%2][s[i]%2]++;
        }
        int ans=INT_MAX;
        if(cnt[0][0]==cnt[1][1]){
            chmin(ans,cnt[0][0]);
        }
        if(cnt[0][1]==cnt[1][0]){
            chmin(ans,cnt[0][1]);
        }
        return ans==INT_MAX?-1:ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="111000";
    auto ans=sol.minSwaps(s);
    DBG(ans);

    system("pause");
    return 0;
}
