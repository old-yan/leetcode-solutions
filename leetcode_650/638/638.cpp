#include "utils.h"

class Solution {
    vi price;
    vvi special;
    vi needs;
    int dp[7][7][7][7][7][7];
    int dfs(vi&lack){
        if(dp[lack[0]][lack[1]][lack[2]][lack[3]][lack[4]][lack[5]]>=0)return dp[lack[0]][lack[1]][lack[2]][lack[3]][lack[4]][lack[5]];
        int res=INT_MAX;
        for(auto&A:special){
            bool can=true;
            REP(i,needs.size()){
                if(A[i]>lack[i])can=false;
            }
            if(can){
                REP(i,needs.size())lack[i]-=A[i];
                chmin(res,dfs(lack)+A.back());
                REP(i,needs.size())lack[i]+=A[i];
            }
        }
        REP(i,needs.size()){
            if(lack[i]){
                lack[i]--;
                chmin(res,dfs(lack)+price[i]);
                lack[i]++;
            }
        }
        return dp[lack[0]][lack[1]][lack[2]][lack[3]][lack[4]][lack[5]]=res;
    }
public:
    int shoppingOffers(vector<int>&_price, vector<vector<int>>&_special, vector<int>&_needs) {
        price=_price;
        {
            vector<bool>bad(_special.size(),false);
            REP(i,_special.size()-1){
                int sum=0;
                REP(k,_price.size()){
                    sum+=_price[k]*_special[i][k];
                }
                if(sum<=_special[i].back()){
                    bad[i]=true;
                    continue;
                }
                REP(j,_special.size()-1){
                    if(i==j)continue;
                    bool pass=false;
                    int add=0;
                    REP(k,_price.size()){
                        if(_special[i][k]<_special[j][k]){
                            pass=true;
                            break;
                        }
                        add+=(_special[i][k]-_special[j][k])*_price[k];
                    }
                    if(pass)continue;
                    if(_special[j].back()+add<=_special[i].back()){
                        bad[i]=true;
                        break;
                    }
                }
            }
            REP(i,_special.size()){
                if(!bad[i])special.emplace_back(_special[i]);
            }
        }
        needs=_needs;
        vi lack=needs;
        lack.resize(6,0);
        memset(dp,0xff,sizeof(dp));
        dp[0][0][0][0][0][0]=0;
        return dfs(lack);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi price{2,5};
    vvi special{
        {3,0,5},{1,2,10}
    };
    vi needs{3,2};
    auto ans=sol.shoppingOffers(price,special,needs);
    DBG(ans);

    system("pause");
    return 0;
}
