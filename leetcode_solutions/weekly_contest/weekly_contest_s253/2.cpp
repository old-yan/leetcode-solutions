#include "utils.h"

class Solution {
public:
    //一看k数字不太大，可以模拟，每次把堆中最大的拿出来减半
    int minStoneSum(vector<int>& piles, int k) {
        ll sum=accumulate(ALL(piles),0ll);
        priority_queue<int>Q(ALL(piles));
        while(k--){
            auto p=Q.top();Q.pop();
            sum-=p/2;
            p-=p/2;
            Q.push(p);
        }
        return sum;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi piles{4,3,6,7};
    int k=3;
    auto ans=sol.minStoneSum(piles,k);
    DBG(ans);

    system("pause");
    return 0;
}
