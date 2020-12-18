#include "utils.h"

class Solution {
    unordered_map<int,int>lowerbound,upperbound;
    int Find(int i){
        if(lowerbound[i]==i)return i;
        else return lowerbound[i]=Find(lowerbound[i]);
    }
public:
    int longestConsecutive(vector<int>& nums) {
        for(int a:nums){
            if(lowerbound.count(a))continue;
            lowerbound[a]=a;
            if(lowerbound.count(a-1)){
                lowerbound[a]=Find(a-1);
            }
            if(lowerbound.count(a+1)){
                lowerbound[a+1]=Find(a);
            }
        }
        int ans=0;
        for(auto it:lowerbound){
            chmax(ans,it.first-Find(it.first)+1);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{100,4,200,1,3,2};
    auto ans=sol.longestConsecutive(nums);
    DBG(ans);

    system("pause");
    return 0;
}
