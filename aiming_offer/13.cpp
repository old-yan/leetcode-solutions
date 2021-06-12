#include "Union.h"
#include "utils.h"

Union u(10000);
class Solution {
public:
    int movingCount(int m, int n, int k) {
        u.reset();
        bool ban[m][n];
        memset(ban,0,sizeof(ban));
        REP(i,m)REP(j,n){
            int cnt=0;
            for(int cur=i;cur;cur/=10)cnt+=cur%10;
            for(int cur=j;cur;cur/=10)cnt+=cur%10;
            if(cnt>k)ban[i][j]=true;
        }
        REP(i,m)REP(j,n)if(!ban[i][j])REP(k,4){
            int ii=i+di[k],jj=j+dj[k];
            if(VALID&&!ban[ii][jj])u.unite(i*n+j,ii*n+jj);
        }
        return u.size[0];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int m=2;
    int n=3;
    int k=1;
    auto ans=sol.movingCount(m,n,k);
    DBG(ans);

    system("pause");
    return 0;
}
