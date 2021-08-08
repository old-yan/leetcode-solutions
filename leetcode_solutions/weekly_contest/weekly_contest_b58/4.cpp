#include "utils.h"

class Solution {
    //本函数基本由马拉车算法改编而来
    //区别：
    //  1.  由于是找奇数长度回文串，对称轴一定在字母上而不在两个字母中间。所以不需要用其它字符插空；
    //  2.  在推进maxright的时候，顺便利用此时的对称轴更新maxright下标处的最长回文串长度
    //  3.  最后要求出前缀最大值，返回 len 数组而不是 arm 数组
    vi getlen(string s){
        int middle,maxright=0;
        vi arm(s.size(),0);
        vi len(s.size(),1);
        FOR(i,1,s.size()-1){
            if(i<=maxright){
                int opp=middle*2-i;
                if(opp-arm[opp]==middle*2-maxright){
                    int l=i-arm[opp],r=i+arm[opp];
                    while(l>0&&r<s.size()&&s[l-1]==s[r+1])l--,r++;
                    arm[i]=r-i;
                    if(maxright<r){
                        FOR(j,maxright+1,r+1)len[j]=(j-i)*2+1;
                        maxright=r;
                        middle=i;
                    }
                }
                else arm[i]=min(arm[opp],maxright-int(i));
            }
            else{
                int l=i,r=i;
                while(l>0&&r<s.size()&&s[l-1]==s[r+1])l--,r++;
                arm[i]=r-i;
                if(maxright<r){
                    FOR(j,maxright+1,r+1)len[j]=(j-i)*2+1;
                    maxright=r;
                    middle=i;
                }
            }
        }
        partial_sum(ALL(len),len.begin(),[](int x,int y){return x>y?x:y;});
        return len;
    }
public:
    //借助马拉车算法，线性获取前缀最大回文串、后缀最大回文串
    long long maxProduct(string s) {
        //求出前缀最大回文串
        auto v1=getlen(s);
        //反向
        reverse(ALL(s));
        //求出反向的前缀最大回文串
        auto v2=getlen(s);
        //再次反向，即为后缀最大回文串
        reverse(ALL(v2));
        ll ans=1;
        //以i为分界线，i前面找个前缀串，i以及i之后找个后缀串
        FOR(i,1,s.size())ans=max(ans,1ll*v1[i-1]*v2[i]);
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="ababbb";
    auto ans=sol.maxProduct(s);
    DBG(ans);

    system("pause");
    return 0;
}
