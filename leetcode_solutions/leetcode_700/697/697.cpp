#include "utils.h"

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int Minidx[50000],Maxidx[50000];
        unordered_map<int,int>M;
        int maxDeg=0;
        REP(i,nums.size()){
            if(!M[nums[i]]++){
                Minidx[nums[i]]=i;
                Maxidx[nums[i]]=i;
            }
            else{
                chmax(Maxidx[nums[i]],int(i));
                chmin(Minidx[nums[i]],int(i));
            }
            chmax(maxDeg,M[nums[i]]);
        }
        int ans=INT_MAX;
        for(auto&it:M){
            if(it.second==maxDeg){
                chmin(ans,Maxidx[it.first]-Minidx[it.first]+1);
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{1,2,2,3,1};
    auto ans=sol.findShortestSubArray(nums);
    DBG(ans);

    system("pause");
    return 0;
}
