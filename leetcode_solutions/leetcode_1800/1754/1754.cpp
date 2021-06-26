#include "SuffixArray.h"
#include "utils.h"

class Solution {
public:
    string largestMerge(string word1, string word2) {
        SuffixArray sa(word1+"#"+word2);
        string ans;
        for(int i=0,j=0;i<word1.size()||j<word2.size();){
            if(i==word1.size()){
                while(j<word2.size())ans+=word2[j++];
            }
            else if(j==word2.size()){
                while(i<word1.size())ans+=word1[i++];
            }
            else{
                if(sa.rk[i]<sa.rk[word1.size()+j+1])ans+=word1[i++];
                else ans+=word2[j++];
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string word1="cabaa";
    string word2="bcaaa";
    auto ans=sol.largestMerge(word1,word2);
    DBG(ans);

    system("pause");
    return 0;
}
