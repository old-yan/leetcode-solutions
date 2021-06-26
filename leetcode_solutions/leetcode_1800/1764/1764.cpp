#include "utils.h"

class Solution {
public:
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        int m=groups.size(),n=nums.size();
        for(int i=0,j=0;i<m;){
            if(j==n)return false;
            bool flag=true;
            REP(k,groups[i].size()){
                if(j+k==nums.size()||nums[j+k]!=groups[i][k]){
                    flag=false;
                    break;
                }
            }
            if(flag){
                j+=groups[i].size();
                i++;
            }
            else j++;
        }
        return true;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi groups=makevvi("[[1,-1,-1],[3,-2,0]]");
    vi nums{1,-1,0,1,-1,-1,3,-2,0};
    auto ans=sol.canChoose(groups,nums);
    DBG(ans);

    system("pause");
    return 0;
}
