#include "utils.h"

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        if(!n)return 0;
        int left[n],right[n];
        stack<int>S;
        REP(i,n){
            while(S.size()&&heights[S.top()]>=heights[i]){
                right[S.top()]=i-S.top()-1;
                S.pop();
            }
            if(S.empty())left[i]=i;
            else left[i]=i-S.top()-1;
            S.push(i);
        }
        while(S.size()){
            right[S.top()]=n-S.top()-1;
            S.pop();
        }
        int ans=0;
        REP(i,n)chmax(ans,heights[i]*(1+left[i]+right[i]));
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi heights{2,1,5,6,2,3};
    auto ans=sol.largestRectangleArea(heights);
    DBG(ans);

    system("pause");
    return 0;
}
