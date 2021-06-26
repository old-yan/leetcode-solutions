#include "utils.h"

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int,int>deg;
        for(auto&e:edges){
            int i=e[0],j=e[1];
            if(++deg[i]>1)return i;
            if(++deg[j]>1)return j;
        }
        return -1;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi edges=makevvi("[[1,2],[2,3],[4,2]]");
    auto ans=sol.findCenter(edges);
    DBG(ans);

    system("pause");
    return 0;
}
