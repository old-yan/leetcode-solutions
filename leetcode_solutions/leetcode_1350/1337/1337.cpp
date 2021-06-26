#include "utils.h"

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m=mat.size(),n=mat[0].size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>Q;
        REP(i,m){
            int ones=[&](){
                int low=0,high=n;
                while(low<high){
                    int mid=low+high>>1;
                    if(mat[i][mid]==0)high=mid;
                    else low=mid+1;
                }
                return low;
            }();
            Q.emplace(ones,i);
        }
        vi ans;
        while(ans.size()<k){
            ans.pb(Q.top().second);
            Q.pop();
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi mat=makevvi("[[1,1,0,0,0],[1,1,1,1,0],[1,0,0,0,0],[1,1,0,0,0],[1,1,1,1,1]]");
    int k=3;
    auto ans=sol.kWeakestRows(mat,k);
    DBGV(ans);

    system("pause");
    return 0;
}
