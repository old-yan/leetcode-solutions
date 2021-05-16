#include "utils.h"

class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int>Q;
        int Min=INT_MAX;
        for(int a:nums){
            if(a%2)a<<=1;
            chmin(Min,a);
            Q.push(a);
        }
        int end=Min,ans=INT_MAX;
        while(Q.top()>=Min){
            auto p=Q.top();
            Q.pop();
            chmin(ans,p-Min);
            if(p%2==0)p>>=1;
            else break;
            chmin(Min,p);
            Q.push(p);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{8,1,2,1};
    auto ans=sol.minimumDeviation(nums);
    DBG(ans);

    system("pause");
    return 0;
}
