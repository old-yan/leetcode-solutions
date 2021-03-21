#include "utils.h"

class Solution {
public:
    //模拟，用两个map盛放有序的buy订单和sell订单，buy升序盛放，sell降序盛放
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        map<int,ll>sell;
        map<int,ll,greater<int>>buy;
        ll ans=0;
        for(auto&order:orders){
            ll p=order[0],amount=order[1],type=order[2];
            if(type==0){
                while(sell.size()&&sell.begin()->first<=p){
                    if(sell.begin()->second<=amount){
                        amount-=sell.begin()->second;
                        ans-=sell.begin()->second;
                        sell.erase(sell.begin());
                        if(!amount)break;
                    }
                    else{
                        sell.begin()->second-=amount;
                        ans-=amount;
                        amount=0;
                        break;
                    }
                }
                if(amount){
                    buy[p]+=amount;
                    ans+=amount;
                }
            }
            else{
                while(buy.size()&&buy.begin()->first>=p){
                    if(buy.begin()->second<=amount){
                        amount-=buy.begin()->second;
                        ans-=buy.begin()->second;
                        buy.erase(buy.begin());
                        if(!amount)break;
                    }
                    else{
                        buy.begin()->second-=amount;
                        ans-=amount;
                        amount=0;
                        break;
                    }
                }
                if(amount){
                    sell[p]+=amount;
                    ans+=amount;
                }
            }
        }
        return ans%MOD;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi orders=makevvi("[[7,1000000000,1],[15,3,0],[5,999999995,0],[5,1,1]]");
    auto ans=sol.getNumberOfBacklogOrders(orders);
    DBG(ans);

    system("pause");
    return 0;
}
