#include "utils.h"

class Solution {
public:
    int busRapidTransit(int target, int inc, int dec, vector<int>& jump, vector<int>& cost) {
        int m=jump.size();
        unordered_map<ll,ll>M;
        M[target]=0;
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>Q;
        Q.emplace(0,target);
        while(Q.size()){
            auto [d,p]=Q.top();
            Q.pop();
            if(d!=M[p])continue;
            if(!p)return d%MOD;
            REP(i,m){
                ll q=p/jump[i],r=p%jump[i];
                ll c=q?cost[i]:0;
                if(!M.count(q)){
                    M[q]=d+min(inc*(p-q),inc*r+c);
                    Q.emplace(M[q],q);
                }
                else if(chmin(M[q],d+min(inc*(p-q),inc*r+c))){
                    Q.emplace(M[q],q);
                }
                if(!M.count(q+1)){
                    M[q+1]=d+min(inc*(p-q-1),dec*(jump[i]-r)+cost[i]);
                    Q.emplace(M[q+1],q+1);
                }
                else if(chmin(M[q+1],d+min(inc*(p-q-1),dec*(jump[i]-r)+cost[i]))){
                    Q.emplace(M[q+1],q+1);
                }
            }
        }
        return -1;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int target=31;
    int inc=5;
    int dec=3;
    vi jump{6};
    vi cost{10};
    auto ans=sol.busRapidTransit(target,inc,dec,jump,cost);
    DBG(ans);

    system("pause");
    return 0;
}
