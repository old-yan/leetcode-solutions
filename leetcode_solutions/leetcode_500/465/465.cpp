#include "utils.h"

class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        int l1=s1.size(),l2=s2.size();
        int dp[l2][2];
        REP(i,l2){
            int cycle=0;
            int cur=i;
            for(char c:s1){
                if(c==s2[cur]){
                    cur=(cur+1)%l2;
                    if(!cur)cycle++;
                }
            }
            dp[i][0]=cur;
            dp[i][1]=cycle;
        }
        unordered_map<int,int>M;
        int cur=0;
        vi sum;
        REP(i,n1){
            if(M.count(cur)){
                int last=M[cur];
                if((n1-i)%(i-last)==0){
                    return (sum.back()+(n1-i)/(i-last)*(sum.back()-(last-1>=0?sum[last-1]:0)))/n2;
                }
            }
            M[cur]=i;
            if(sum.size())sum.pb(sum.back()+dp[cur][1]);
            else sum.pb(dp[cur][1]);
            cur=dp[cur][0];
        }
        return sum.size()?sum.back()/n2:0;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s1="acb";
    int n1=4;
    string s2="ab";
    int n2=2;
    auto ans=sol.getMaxRepetitions(s1,n1,s2,n2);
    DBG(ans);

    system("pause");
    return 0;
}
