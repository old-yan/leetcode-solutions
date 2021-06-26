#include "utils.h"

class Solution {
public:
    int shortestBridge(vector<vector<int>>& A) {
        int r,c;
        int m=A.size(),n=A[0].size();
        for(r=0;r<m;r++){
            for(c=0;c<n&&!A[r][c];c++);
            if(c<n)break;
        }
        deque<pair<int,int>>v;
        v.emplace_back(r,c);
        A[r][c]=-1;
        REP(_,v.size()){
            auto [i,j]=v[_];
            REP(k,4){
                int ii=i+di[k],jj=j+dj[k];
                if(VALID&&A[ii][jj]==1){
                    A[ii][jj]=-1;
                    v.emplace_back(ii,jj);
                }
            }
        }
        queue<pair<int,int>>Q(v);
        int ans=0;
        while(Q.size()){
            auto [i,j]=Q.front();
            Q.pop();
            REP(k,4){
                int ii=i+di[k],jj=j+dj[k];
                if(!VALID)continue;
                if(!A[ii][jj]){
                    A[ii][jj]=A[i][j]-1;
                    Q.emplace(ii,jj);
                }
                else if(A[ii][jj]==1){
                    ans=-A[i][j]-1;
                    break;
                }
            }
            if(ans)break;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi A=makevvi("[[0,1,0],[0,0,0],[0,0,1]]");
    auto ans=sol.shortestBridge(A);
    DBG(ans);

    system("pause");
    return 0;
}
