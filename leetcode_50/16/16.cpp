#include "utils.h"

class Solution {
    vi next,prev,copy;
    int mindis=INT_MAX,ans,target;
    void dfs(int i){
        int cursum=copy[i];
        int l=i+1,r=copy.size()-1;
        while(l<r){
            int sum=cursum+copy[l]+copy[r];
            if(chmin(mindis,abs(sum-target)))ans=sum;
            if(sum==target){
                l=next[l];
                r=prev[r];
            }
            else if(sum<target)l=next[l];
            else r=prev[r];
        }
    }
public:
    int threeSumClosest(vector<int>& nums, int _target) {
        copy=nums;
        target=_target;
        sort(ALL(copy));
        next=next_different(copy);
        prev=prev_different(copy);
        for(int i=0;i<copy.size();i=next[i]){
            dfs(i);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{-1,-1,1,1,3};
    int target=3;
    auto ans=sol.threeSumClosest(nums,target);
    DBG(ans);
    

    system("pause");
    return 0;
}
