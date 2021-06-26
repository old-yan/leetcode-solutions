#include "utils.h"

class Solution {
public:
    //可以分奇数和偶数两种情况讨论
    int minFlips(string s) {
        int n=s.size();
        //偶数情况下，没什么好说的，不是变成0101就是变成1010
        if(n%2==0){
            string t;
            REP(i,n){
                if(i%2)t+='0';
                else t+='1';
            }
            int dif=0;
            REP(i,s.size())dif+=s[i]!=t[i];
            return min(dif,(int(s.size()))-dif);
        }
        //技术情况下，把字符串分成两截，前半截和后半截的相位可以相反
        else{
            string t1,t2;
            REP(i,s.size()){
                if(i%2)t1+='0',t2+='1';
                else t1+='1',t2+='0';
            }
            //先算出前缀和
            //dif1是s和t1的不同数量，从前往后前缀和
            //dif2是s和t2的不同数量，从后往前前缀和
            int dif1[n+1],dif2[n+1];
            REP(i,n){
                dif1[i]=i?dif1[i-1]+(s[i]!=t1[i]):s[0]!=t1[0];
            }
            dif2[n]=0;
            REPR(i,n-1){
                dif2[i]=dif2[i+1]+(s[i]!=t2[i]);
            }
            int ans=INT_MAX;
            //枚举i作为前半截的尾字符
            REP(i,n){
                chmin(ans,dif1[i]+dif2[i+1]);
                chmin(ans,int((i+1-dif1[i])+(n-i-1-dif2[i+1])));
            }
            return ans;
        }
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="01001001101";
    auto ans=sol.minFlips(s);
    DBG(ans)

    system("pause");
    return 0;
}
