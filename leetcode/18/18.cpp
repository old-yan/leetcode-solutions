#include "utils.h"

class Solution {
    vi next,prev,copy;
    int target;
    vvi ans;
    int path[4];
    void dfs(int i,int idx){
        path[idx]=copy[i];
        if(idx<1){
            for(int j=i+1;j<copy.size();j=next[j])dfs(j,1);
        }
        else{
            int l=i+1,r=copy.size()-1;
            int cursum=path[0]+path[1];
            while(l<r){
                int sum=cursum+copy[l]+copy[r];
                if(sum==target){
                    path[2]=copy[l];
                    path[3]=copy[r];
                    ans.push_back(vi(path,path+4));
                    l=next[l];
                    r=prev[r];
                }
                else if(sum<target)l=next[l];
                else r=prev[r];
            }
        }
    }
public:
    vector<vector<int>> fourSum(vector<int>& nums, int _target) {
        copy=nums;
        sort(ALL(copy));
        next=next_different(copy);
        prev=prev_different(copy);
        target=_target;
        for(int i=0;i<copy.size();i=next[i]){
            dfs(i,0);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{1, 0, -1, 0, -2, 2};
    int target=0;
    auto ans=sol.fourSum(nums,target);
    DBGVV(ans);
    

    system("pause");
    return 0;
}
