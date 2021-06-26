#include "utils.h"

class Solution {
public:
    int maxProfit(vector<int>& inventory, int orders) {
        vector<ll>presum{0};
        sort(ALL(inventory));
        for(int a:inventory)presum.pb(presum.back()+a);
        int low=0,high=*max_element(ALL(inventory));
        while(low<high){
            int mid=(low+high)/2;
            int num=lower_bound(ALL(inventory),mid)-inventory.begin();
            ll can=presum.back()-presum[num]-(ll)(inventory.size()-num)*mid;
            if(can<=orders)high=mid;
            else low=mid+1;
        }
        int num=lower_bound(ALL(inventory),low)-inventory.begin();
        ll can=presum.back()-presum[num]-(ll)(inventory.size()-num)*low;
        ll sum=0;
        for(int a:inventory){
            if(a>low){
                sum+=(ll)(a+low+1)*(a-low)/2;
            }
        }
        sum+=(orders-can)*low;
        return sum;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi inventory{2,5};
    int orders=4;
    auto ans=sol.maxProfit(inventory,orders);
    DBG(ans);

    system("pause");
    return 0;
}
