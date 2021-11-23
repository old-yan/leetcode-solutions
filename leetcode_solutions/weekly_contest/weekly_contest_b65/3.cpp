#include "utils.h"

class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(),items.end());
        //预处理出美丽值的前缀最大
        vector<int>premax{0};
        for(auto& a:items)premax.push_back(max(premax.back(),a[1]));
        vector<int>ans;
        for(int q:queries){
            //二分找到价格界限，读取那里的前缀最大值
            int low=0,high=items.size();
            while(low<high){
                int mid=low+high>>1;
                if(items[mid][0]>q)high=mid;
                else low=mid+1;
            }
            ans.push_back(premax[low]);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<vector<int>>items=makevvi("[[1,2],[3,2],[2,4],[5,6],[3,5]]");
    vector<int>queries{1,2,3,4,5,6};
    auto ans=sol.maximumBeauty(items,queries);
    DBGV(ans);

    system("pause");
    return 0;
}