#include "utils.h"

class Solution {
    class adder{
    public:
        int i,j,sum;
        adder(int _i,int _j,int _sum):i(_i),j(_j),sum(_sum){}
    };
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vvi ans;
        if(nums1.empty()||nums2.empty())return ans;
        auto comp=[&](adder*x,adder*y){return x->sum>y->sum;};
        priority_queue<adder*,vector<adder*>,decltype(comp)>Q(comp);
        REP(i,nums1.size()){
            Q.push(new adder(i,0,nums1[i]+nums2[0]));
        }
        while(ans.size()<k&&Q.size()){
            auto p=Q.top();
            Q.pop();
            ans.pb({nums1[p->i],nums2[p->j]});
            if(++p->j<nums2.size()){
                p->sum=nums1[p->i]+nums2[p->j];
                Q.push(p);
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums1{1,1,2};
    vi nums2{1,1,2,3};
    int k=5;
    auto ans=sol.kSmallestPairs(nums1,nums2,k);
    DBGVV(ans);

    system("pause");
    return 0;
}
