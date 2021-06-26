#include "utils.h"

class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(ALL(tasks),[](vi&x,vi&y){return x[1]-x[0]<y[1]-y[0];});
        int cur=0;
        for(auto&t:tasks){
            cur=max(t[1],cur+t[0]);
        }
        return cur;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi tasks=makevvi("[[1,2],[2,4],[4,8]]");
    auto ans=sol.minimumEffort(tasks);
    DBG(ans);

    system("pause");
    return 0;
}
