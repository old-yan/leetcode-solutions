#include "utils.h"

class Solution {
    int indeg[1001]={0},outdeg[1001]={0};
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        for(auto&t:trust){
            indeg[t[1]]++;
            outdeg[t[0]]++;
        }
        int ans=0;
        FOR(i,1,1001){
            if(!outdeg[i]&&indeg[i]==N-1){
                if(ans)return -1;
                else ans=i;
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int N=3;
    vvi trust=makevvi("[[1,3],[2,3]]");
    auto ans=sol.findJudge(N,trust);
    DBG(ans);

    system("pause");
    return 0;
}
