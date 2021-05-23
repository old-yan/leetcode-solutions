#include "utils.h"

class Solution {
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        priority_queue<pair<int,int>>Qbuy;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>Qsell;
        ll ans=0;
        for(auto&o:orders){
            if(o[2]==0){
                while(Qsell.size()){
                    auto [p,n]=Qsell.top();
                    if(p>o[0])break;
                    Qsell.pop();
                    int q=min(n,o[1]);
                    ans-=q;
                    if(n-=q)Qsell.emplace(p,n);
                    if(!(o[1]-=q))break;
                }
                if(o[1]){
                    ans+=o[1];
                    Qbuy.emplace(o[0],o[1]);
                }
            }
            else{
                while(Qbuy.size()){
                    auto [p,n]=Qbuy.top();
                    if(p<o[0])break;
                    Qbuy.pop();
                    int q=min(n,o[1]);
                    ans-=q;
                    if(n-=q)Qbuy.emplace(p,n);
                    if(!(o[1]-=q))break;
                }
                if(o[1]){
                    ans+=o[1];
                    Qsell.emplace(o[0],o[1]);
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

    vvi orders=makevvi("[[10,5,0],[15,2,1],[25,1,1],[30,4,0]]");
    auto ans=sol.getNumberOfBacklogOrders(orders);
    DBG(ans);

    system("pause");
    return 0;
}
