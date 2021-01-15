#include "utils.h"

class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        vector<char>v;
        for(char c:S){
            if(c!='-')v.pb(toupper(c));
        }
        string ans;
        int cur=K-v.size()%K;
        REP(i,v.size()){
            ans+=v[i];
            cur++;
            if(cur%K==0&&i+1<v.size())ans+='-';
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string S="5F3Z-2e-9-w";
    int K=4;
    auto ans=sol.licenseKeyFormatting(S,K);
    DBG(ans);

    system("pause");
    return 0;
}
