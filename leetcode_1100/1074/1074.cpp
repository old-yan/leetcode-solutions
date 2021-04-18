#include "utils.h"

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m=matrix.size(),n=matrix[0].size();
        int ans=0;
        REP(i,m){
            int colsum[n];
            memset(colsum,0,sizeof(colsum));
            FOR(j,i,m){
                auto row=matrix[j];
                REP(k,n)colsum[k]+=row[k];
                partial_sum(colsum,colsum+n,colsum);
                static unordered_map<int,int>M;
                M.clear();
                M[0]=1;
                for(int a:colsum){
                    auto find=M.find(a-target);
                    if(find!=M.end())ans+=find->second;
                    M[a]++;
                }
                adjacent_difference(colsum,colsum+n,colsum);
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi matrix=makevvi("[[0,1,0],[1,1,1],[0,1,0]]");
    int target=0;
    auto ans=sol.numSubmatrixSumTarget(matrix,target);
    DBG(ans);

    system("pause");
    return 0;
}
