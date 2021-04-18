#include "utils.h"

//预处理一张长度3000的逆元表
static vi invt=invTable(3000);
class Solution {
    //统计剩余字符数量
    ll cnt[26]={0};
    //维护每个字符作为起始字符的排列数
    ll cur[26];
    int n;
    //计算初始排列数
    ll init_comp(){
        ll val=1;
        FOR(j,1,n+1)val=val*j%MOD;
        REP(c,26){
            FOR(j,1,cnt[c]+1){
                val=val*invt[j]%MOD;
            }
        }
        return val;
    }
public:
    //在纸上画图分析，发现本题操作本质上就是将当前排列变为上一个排列
    //本题转化为：当前排列在全排列里的字典序排名
    int makeStringSorted(string s) {
        n=s.size();
        for(char c:s)cnt[c-'a']++;
        ll val=init_comp();
        //动态维护cur数组的方法比较复杂
        REP(i,26){
            if(cnt[i]){
                cur[i]=val*invt[n]%MOD*cnt[i]%MOD;
            }
        }
        ll ans=0;
        REP(j,n){
            REP(i,26){
                if(cnt[i]){
                    if(i<s[j]-'a')ans+=cur[i];
                    cur[i]=cur[i]*invt[n-j-1]%MOD*(cnt[s[j]-'a']-(i==s[j]-'a'))%MOD;
                }
            }
            cnt[s[j]-'a']--;
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
