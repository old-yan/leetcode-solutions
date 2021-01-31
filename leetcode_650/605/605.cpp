#include "utils.h"

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        vi next=next_different(flowerbed);
        int ans=0;
        for(int i=0;i<next.size();i=next[i]){
            if(flowerbed[i]==1)continue;
            int j=next[i]-i-1;
            if(!i)j++;
            if(next[i]==flowerbed.size())j++;
            ans+=j/2;
        }
        return ans>=n;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi flowerbed{1,0,0,0,1};
    int n=2;
    auto ans=sol.canPlaceFlowers(flowerbed,n);
    DBG(ans);

    system("pause");
    return 0;
}
