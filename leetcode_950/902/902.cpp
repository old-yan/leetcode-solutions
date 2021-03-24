#include "utils.h"

const ll units[11]={1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000,10000000000ll};
class Solution {
    int ans=0;
    void dfs(int curidx,ll cur,vector<string>&digits,ll n){
        if(curidx<0)ans+=cur<=n;
        else{
            if(cur/units[curidx+1]==n/units[curidx+1]){
                for(string&s:digits){
                    dfs(curidx-1,cur+units[curidx]*(s[0]-'0'),digits,n);
                }
            }
            else if(cur/units[curidx+1]<n/units[curidx+1]){
                ans+=pow(digits.size(),curidx+1);
            }
        }
    }
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        if(n>=10){
            FORR(i,log10(n),1){
                ans+=pow(digits.size(),i);
            }
        }
        dfs(log10(n),0,digits,n);
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<string>digits{"1","3","5","7"};
    int n=100;
    auto ans=sol.atMostNGivenDigitSet(digits,n);
    DBG(ans);

    system("pause");
    return 0;
}
