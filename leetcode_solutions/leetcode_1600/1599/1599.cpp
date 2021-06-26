#include "utils.h"

class Solution {
public:
    int minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost) {
        int ans=-1,ans_num=0,rest=accumulate(ALL(customers),0);
        int n=customers.size();
        for(int i=0,j=0,k=0;j||rest;i++){
            if(i<customers.size()){
                j+=customers[i];
                rest-=customers[i];
            }
            k+=min(4,j)*boardingCost;
            j-=min(4,j);
            k-=runningCost;
            if(chmax(ans_num,k))ans=i+1;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi customers{8,3};
    int boardingCost=5;
    int runningCost=6;
    auto ans=sol.minOperationsMaxProfit(customers,boardingCost,runningCost);
    DBG(ans);

    system("pause");
    return 0;
}
