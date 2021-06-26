#include "utils.h"

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        vi v(s.size());
        REP(i,s.size()){
            v[i]=abs(s[i]-t[i]);
        }
        int ans=0;
        for(int i=0,j=0,k=0;i<s.size();i++){
            while(j<v.size()&&k+v[j]<=maxCost){
                k+=v[j++];
            }
            chmax(ans,j-i);
            k-=v[i];
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="abcd";
    string t="bcdf";
    int maxCost=3;
    auto ans=sol.equalSubstring(s,t,maxCost);
    DBG(ans);

    system("pause");
    return 0;
}
