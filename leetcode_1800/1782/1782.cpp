#include "utils.h"

class Solution {
    int deg[20000]={0};
    unordered_map<int,int>M;
public:
    vector<int> countPairs(int n, vector<vector<int>>& edges, vector<int>& queries) {
        for(auto&e:edges){
            int i=e[0]-1,j=e[1]-1;
            if(i>j)swap(i,j);
            deg[i]++;
            deg[j]++;
            M[i*30000+j]++;
        }
        int Max=*max_element(deg,deg+n);
        vi degmap(Max+1,0);
        REP(i,n)degmap[deg[i]]++;
        partial_sum(ALLR(degmap),degmap.rbegin());
        vi ans;
        for(auto&q:queries){
            int cnt=0;
            REP(i,n){
                int j=q-deg[i]+1;
                if(j<0)cnt+=n;
                else if(j<=Max)cnt+=degmap[j];
                if(deg[i]*2>q)cnt--;
            }
            for(auto&[p,k]:M){
                int i=p/30000,j=p%30000;
                if(deg[i]+deg[j]>q&&deg[i]+deg[j]-k<=q)cnt-=2;
            }
            ans.pb(cnt/2);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=4;
    vvi edges=makevvi("[[1,2],[2,4],[1,3],[2,3],[2,1]]");
    vi queries{2,3};
    auto ans=sol.countPairs(n,edges,queries);
    DBGV(ans);

    system("pause");
    return 0;
}
