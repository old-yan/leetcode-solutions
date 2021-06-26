#include "utils.h"

class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int M[100]={0};
        int ans=0;
        for(auto&d:dominoes){
            if(d[0]>d[1])swap(d[0],d[1]);
            int a=d[0]*10+d[1];
            ans+=M[a]++;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi dominoes=makevvi("[[1,2],[2,1],[3,4],[5,6]]");
    auto ans=sol.numEquivDominoPairs(dominoes);
    DBG(ans);

    system("pause");
    return 0;
}
