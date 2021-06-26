#include "SuffixArray.h"
#include "Union.h"
#include "utils.h"

class Solution {
public:
    int maxFreq(string &s, int maxLetters, int minSize, int maxSize) {
        int n=s.size();
        SuffixArray sa(s);
        sa.getHeight();
        int ans=0;
        Union u(n);
        FOR(i,1,n){
            if(sa.height[i]>=minSize)u.unite(sa.sa[i],sa.sa[i-1]);
        }
        int res[n];
        memset(res,0,sizeof(res));
        char cnt[26]={0},nonzero=0;
        for(int i=0,j=0;i<n;i++){
            while(j<n&&j<i+minSize){
                if(!cnt[s[j++]-'a']++)nonzero++;
            }
            if(j-i<minSize)break;
            if(nonzero<=maxLetters){
                chmax(ans,++res[u.Find(i)]);
            }
            if(!--cnt[s[i]-'a'])nonzero--;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="aababcaab";
    int maxLetters=2;
    int minSize=3;
    int maxSize=4;
    auto ans=sol.maxFreq(s,maxLetters,minSize,maxSize);
    DBG(ans);

    system("pause");
    return 0;
}
