#include "utils.h"

class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        int m=A.size(),n=A[0].size();
        int cnt[n];
        memset(cnt,0,sizeof(cnt));
        for(auto&row:A){
            if(!row[0]){
                for(int&a:row)a=!a;
            }
            REP(i,n)cnt[n-1-i]+=row[i];
        }
        int ans=0;
        REP(i,n){
            ans+=max(cnt[i],m-cnt[i])<<i;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi A=makevvi("[[0,0,1,1],[1,0,1,0],[1,1,0,0]]");
    auto ans=sol.matrixScore(A);
    DBG(ans);

    system("pause");
    return 0;
}
