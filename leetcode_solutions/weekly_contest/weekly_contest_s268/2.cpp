#include "utils.h"

class Solution {
public:
    //本题经典双指针，将整个区间拆分成若干个区间，使每个子区间的和小于等于 capacity
    int wateringPlants(vector<int>& plants, int capacity) {
        int n=plants.size();
        int ans=0;
        for(int i=0;i<n;){
            int j=i;
            int sum=0;
            while(j<n){
                sum+=plants[j];
                // sum 表示下标从 i 到 j 的子区间的区间和
                if(sum>capacity)break;
                else j++;
            }
            //区间 [i,j) 为符合条件的子区间
            //从 -1 赶到 j-1 ，路程为 j，往返就是 j*2
            ans+=j*2;
            // i 改为 j，开始考虑下一个子区间
            i=j;
        }
        //最后一个子区间不需要往返，所以少一个回城
        return ans-n;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<int>plants{2,2,3,3};
    int capacity=5;
    auto ans=sol.wateringPlants(plants,capacity);
    DBG(ans);

    system("pause");
    return 0;
}