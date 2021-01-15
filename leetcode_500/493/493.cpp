#include "utils.h"

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        auto half=[](ll val){
            return val>0?(val-1)/2:(val-2)/2;
        };
        vi elems(nums.size()*2);
        REP(i,nums.size()){
            elems[i*2]=nums[i];
            elems[i*2+1]=half(nums[i]);
        }
        sort(ALL(elems));
        elems.resize(unique(ALL(elems))-elems.begin());
        unordered_map<int,int>M;
        for(int a:elems)M[a]=M.size();
        zkwTree T(elems.size());
        int ans=0;
        REPR(i,nums.size()-1){
            ans+=T(0,M[half(nums[i])]);
            int j=M[nums[i]];
            T.set(j,T[j]+1);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{1,3,2,3,1};
    auto ans=sol.reversePairs(nums);
    DBG(ans);

    system("pause");
    return 0;
}
