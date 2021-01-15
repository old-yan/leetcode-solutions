#include "utils.h"

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vi nextbigger(nums2.size());
        unordered_map<int,int>M;
        stack<int>S;
        REPR(i,nums2.size()-1){
            while(S.size()&&S.top()<=nums2[i])S.pop();
            if(S.empty())nextbigger[i]=-1;
            else nextbigger[i]=S.top();
            M[nums2[i]]=i;
            S.push(nums2[i]);
        }
        vi ans(nums1.size());
        REP(i,ans.size()){
            ans[i]=nextbigger[M[nums1[i]]];
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums1{4,1,2};
    vi nums2{1,3,4,2};
    auto ans=sol.nextGreaterElement(nums1,nums2);
    DBGV(ans);

    system("pause");
    return 0;
}
