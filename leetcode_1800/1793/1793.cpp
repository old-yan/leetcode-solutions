#include "utils.h"

class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n=nums.size();
        int leftSmaller[n],rightSmaller[n];
        stack<int>S;
        REP(i,n){
            while(S.size()&&nums[S.top()]>=nums[i])S.pop();
            leftSmaller[i]=S.size()?S.top():-1;
            S.push(i);
        }
        stack<int>().swap(S);
        REPR(i,n-1){
            while(S.size()&&nums[S.top()]>=nums[i])S.pop();
            rightSmaller[i]=S.size()?S.top():n;
            S.push(i);
        }
        int ans=0;
        REP(i,n){
            if(leftSmaller[i]<k&&rightSmaller[i]>k){
                chmax(ans,(rightSmaller[i]-leftSmaller[i]-1)*nums[i]);
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{1,4,3,7,4,5};
    int k=3;
    auto ans=sol.maximumScore(nums,k);
    DBG(ans);

    system("pause");
    return 0;
}
