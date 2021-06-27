#include "utils.h"

ll presum[100001];
auto _initial=[](){
    presum[0]=1;
    for(int i=1;i<=100000;i++){
        presum[i]=presum[i-1]*i%MOD;
    }
    return 0;
}();
ll query(int l,int r){
    return presum[r]*inv(presum[l-1])%MOD;
}
ll comb(ll m,ll n){
    return query(m-n+1,m)*inv(query(1,n))%MOD;
}

class Solution {
    int fa[100000];
    vi sons[100000];
    //first方案数 second大小
    pair<ll,ll> dfs(int cur){
        vector<pair<ll,ll>> v;
        ll size=0;
        //先把所有子树的方案树和大小都计算出来
        for(int a:sons[cur])if(a!=fa[cur]){
            v.emplace_back(dfs(a));
            size+=v.back().second;
        }
        //rest表示剩余座位数
        ll rest=size;
        ll ans=1;
        for(auto [num,s]:v){
            //在rest个座位里选s个座位放置这个子树的序列
            ans=ans*num%MOD*comb(rest,s)%MOD;
            rest-=s;
        }
        return {ans,size+1};
    }
public:
    //本题考查拓扑排序的方案数，需要使用树形dp
    //一大难点是combination的实现，可以通过前缀和+逆元来实现
    int waysToBuildRooms(vector<int>& prevRoom) {
        REP(i,prevRoom.size()){
            int f=prevRoom[i];
            fa[i]=f;
            if(f>=0)sons[f].pb(i);
        }
        return dfs(0).first;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi prevRoom{-1,0,1};
    auto ans=sol.waysToBuildRooms(prevRoom);
    DBG(ans);

    system("pause");
    return 0;
}
