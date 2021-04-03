#include "utils.h"

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        int n=tokens.size();
        if(!n)return 0;
        sort(ALL(tokens));
        int i=0,j=tokens.size();
        while(i<n&&P>=tokens[i])P-=tokens[i++];
        if(!i)return 0;
        int ans=i;
        while(i<j){
            P+=tokens[--j];
            while(i<j&&P>=tokens[i]){
                P-=tokens[i++];
            }
            chmax(ans,int(i+j-tokens.size()));
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi tokens{100,200,300,400};
    int P=200;
    auto ans=sol.bagOfTokensScore(tokens,P);
    DBG(ans);

    system("pause");
    return 0;
}
