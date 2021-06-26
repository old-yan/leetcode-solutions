#include "utils.h"

class Solution {
    vi next;
    vi prev;
    vvi ans;
    vi copy;
    void dfs(int i){
        int cursum=copy[i];
        int l=i+1,r=copy.size()-1;
        while(l<r){
            if(copy[l]+copy[r]==-cursum){
                ans.pb({copy[i],copy[l],copy[r]});
                l=next[l];
                r=prev[r];
            }
            else if(copy[l]+copy[r]<-cursum)l=next[l];
            else r=prev[r];
        }
    }
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        copy=nums;
        sort(ALL(copy));
        next=next_different(copy);
        prev=prev_different(copy);
        for(int i=0;i<copy.size();i=next[i])dfs(i);
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{-1, 0, 1, 2, -1, -4};
    auto ans=sol.threeSum(nums);
    DBGVV(ans);

    

    system("pause");
    return 0;
}
