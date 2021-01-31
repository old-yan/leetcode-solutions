#include "utils.h"

class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        //利用哈希表保存每个数的邻居（们）
        unordered_map<int,vi>M;
        for(auto&A:adjacentPairs){
            M[A[0]].pb(A[1]);
            M[A[1]].pb(A[0]);
        }
        int head;
        for(auto&it:M){
            //只有一个邻居的，不是头就是尾
            if(it.second.size()==1){
                head=it.first;
                break;
            }
        }
        vi ans(adjacentPairs.size()+1);
        for(int i=1;i<=adjacentPairs.size();i++){
            if(i==1)ans[i]=M[ans[i-1]][0];
            else ans[i]=M[ans[i-1]][0]+M[ans[i-1]][1]-ans[i-2];
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi adjacentPairs{
        {4,-2},{1,4},{-3,1}
    };
    auto ans=sol.restoreArray(adjacentPairs);
    DBGV(ans);

    system("pause");
    return 0;
}
