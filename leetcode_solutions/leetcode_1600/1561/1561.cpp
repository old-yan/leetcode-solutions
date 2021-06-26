#include "utils.h"

class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(ALLR(piles));
        int n=piles.size()/3;
        int ans=0;
        for(int i=1;i<n*2;i+=2){
            ans+=piles[i];
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi piles{2,4,1,2,7,8};
    auto ans=sol.maxCoins(piles);
    DBG(ans);

    system("pause");
    return 0;
}
