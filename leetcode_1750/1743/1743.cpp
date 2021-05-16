#include "utils.h"

class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int,vi>M;
        for(auto&p:adjacentPairs){
            int i=p[0],j=p[1];
            M[i].pb(j);
            M[j].pb(i);
        }
        int head;
        for(auto&it:M){
            if(it.second.size()==1){
                head=it.first;
                break;
            }
        }
        vi ans{head,M[head][0]};
        while(ans.size()<adjacentPairs.size()+1){
            int last=ans.back();
            auto&v=M[last];
            ans.pb(v[0]+v[1]-ans[ans.size()-2]);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi adjacentPairs=makevvi("[[2,1],[3,4],[3,2]]");
    auto ans=sol.restoreArray(adjacentPairs);
    DBGV(ans);

    system("pause");
    return 0;
}
