#include "utils.h"

class Solution {
public:
    int trap(vector<int>& height) {
        int Maxbefore[height.size()];
        int Maxafter[height.size()];
        REP(i,height.size()){
            if(!i)Maxbefore[i]=0;
            else Maxbefore[i]=max(Maxbefore[i-1],height[i-1]);
        }
        REPR(i,height.size()-1){
            if(i==height.size()-1)Maxafter[i]=0;
            else Maxafter[i]=max(Maxafter[i+1],height[i+1]);
        }
        int ans=0;
        REP(i,height.size()){
            int surface=min(Maxbefore[i],Maxafter[i]);
            if(surface>height[i])ans+=surface-height[i];
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi height{0,1,0,2,1,0,1,3,2,1,2,1};
    auto ans=sol.trap(height);
    DBG(ans);

    system("pause");
    return 0;
}
