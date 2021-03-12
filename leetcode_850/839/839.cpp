#include "utils.h"

class Solution {
public:
    int numSimilarGroups(vector<string>& strs) {
        int n=strs.size();
        int m=strs[0].size();
        Union u(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(u.same(i,j))continue;
                int dif=0;
                for(int k=0;k<m;k++){
                    if(strs[i][k]!=strs[j][k]){
                        if(++dif>2)break;
                    }
                }
                if(dif<=2)u.unite(i,j);
            }
        }
        return u.group;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<string>strs{"tars","rats","arts","star"};
    auto ans=sol.numSimilarGroups(strs);
    DBG(ans);

    system("pause");
    return 0;
}
