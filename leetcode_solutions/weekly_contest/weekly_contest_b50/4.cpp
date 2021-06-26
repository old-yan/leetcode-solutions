#include "SegTree.h"
#include "utils.h"

//预处理一张长度3000的逆元表
vi invt=invTable(3000);
//预处理一张长度3000的阶乘表
vi ft=factorialTable(3000);
//预处理一张长度3000的阶乘逆元表
vi fit=[](){
    vi f(3001);
    for(int i=0;i<=3000;i++){
        f[i]=inv(ft[i]);
    }
    return f;
}();
class Solution {
    int n;
    vi cnt=vi(26,0);
    //计算初始排列数
    ll init_comp(){
        ll val=ft[n];
        REP(c,26){
            val=val*fit[cnt[c]]%MOD;
        }
        return val;
    }
public:
    //在纸上画图分析，发现本题操作本质上就是将当前排列变为上一个排列
    //本题转化为：当前排列在全排列里的字典序排名
    int makeStringSorted(string s) {
        n=s.size();
        for(char c:s)cnt[c-'a']++;
        ll cur=init_comp();
        ll ans=0;
        static SegTree<int>T(26,[](int x,int y){return x+y;});
        T.set(cnt);
        REP(j,n){
            cur=cur*invt[n-j]%MOD;
            ans+=cur*T(0,s[j]-'a'-1);
            T.step_back(s[j]-'a');
            cur=cur*cnt[s[j]-'a']--%MOD;
        }
        return ans%MOD;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;
    
    string s="aabaa";
    auto ans=sol.makeStringSorted(s);
    DBG(ans);

    system("pause");
    return 0;
}
