#include "utils.h"

int lcp[3501][3501]={0};
struct lcphelper{
    string&s;
    lcphelper(string&_s):s(_s){
        for(int i=s.size()-1;i>=0;i--){
            for(int j=0;j<s.size();j++){
                if(s[i]==s[j])lcp[i][j]=lcp[i+1][j+1]+1;
                else lcp[i][j]=0;
            }
        }
    }
    int compare(int i,int j,int len){
        if(lcp[i][j]>=len)return 0;
        else if(s[i+lcp[i][j]]>s[j+lcp[i][j]])return 1;
        else return -1;
    }
};

class Solution {
public:
    //比较明显的一种做法是：num[start:end]是由num[pre:start-1]转移而来，所以要想算出num[start:end]种类数，只要枚举pre就行
    //但是，这种做法是三次方的复杂度，是不能承受的。
    //换个角度想想，如果用dp[end][start]表示num[start:end]的数量，也就是把end放在第一维，start放在第二维
    //那么，dp[end][start]由dp[start-1][pre]转移而来，这个pre根本不需要一一枚举，只需要做了前缀和就可以 O(1) 获取
    int numberOfCombinations(string num) {
        int n=num.size();
        //lcp预处理，一会可能要用
        lcphelper helper(num);
        //dp[end][start]表示从start开始的到end结束的子串有多少种
        ll dp[n][n];
        memset(dp,0,sizeof(dp));
        //枚举end
        for(int end=0;end<n;end++){
            //枚举start，需要小于等于end，且不能为前导零
            for(int start=0;start<=end;start++)if(num[start]!='0'){
                //当前串长度
                int curlen=end-start+1;
                //之前的总长度
                int before=start;
                //如果before小于curlen，说明以start-1为结尾的串统统都小于等于当前串，可以转移
                if(before<curlen)dp[end][start]+=start?dp[start-1][start-1]:1;
                else{
                    //如果before大于等于curlen，不能把前缀和都取走，因为太长的转移不了（题目要求数字不降）
                    //所以要前缀和做差，只拿走能保持不降的情况
                    //短的取走，长的不要，需要额外考虑一下等长子串谁大
                    //  等长子串指的是：num[start -> end]和num[start-curlen -> start-1]
                    //比赛里我采用了memcmp函数，本质上是三次方的算法，但是memcmp函数跑得非常快能跑过
                    //正确时间复杂度的做法，是求出以start开头的子串和start-curlen开头的子串的LCP
                    //LCP有n^2做法也有nlog(n)做法，这里我采用n^2做法
                    //int res=memcmp(&num[start],&num[start-curlen],curlen);
                    int res=helper.compare(start,start-curlen,curlen);
                    //如果当前串大于等于之前的等长串，那么可以取到等长串
                    if(res>=0)dp[end][start]+=dp[start-1][start-1]-(start>curlen?dp[start-1][start-curlen-1]:0)+MOD;
                    //如果当前串小于之前的等长串，那么不取等长串等长串
                    else dp[end][start]+=dp[start-1][start-1]-dp[start-1][start-curlen]+MOD;
                    dp[end][start]%=MOD;
                }
            }
            //每当算完一个end，就对这个end的dp值取前缀和，方便后来者做转移
            partial_sum(dp[end],dp[end+1],dp[end],[](ll x,ll y){return (x+y)%MOD;});
        }
        return dp[n-1][n-1]%MOD;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string num="1023";
    auto ans=sol.numberOfCombinations(num);
    DBG(ans);

    system("pause");
    return 0;
}
