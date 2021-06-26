#include "utils.h"

class Solution {
public:
    int minFlipsMonoIncr(string S) {
        int ans=S.size();
        int leftOnes=0,rightZeros=0;
        for(char c:S)rightZeros+=c=='0';
        for(char c:S){
            chmin(ans,leftOnes+rightZeros);
            if(c=='1')leftOnes++;
            else rightZeros--;
        }
        chmin(ans,leftOnes);
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string S="010110";
    auto ans=sol.minFlipsMonoIncr(S);
    DBG(ans);

    system("pause");
    return 0;
}
