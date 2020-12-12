#include "utils.h"

class Solution {
public:
    // 从宽到窄走，高度逐渐增大
    int maxArea(vector<int>& height) {
        int l=0,r=height.size()-1;
        int ans=0;
        while(l<r){
            chmax(ans,min(height[l],height[r])*(r-l));
            if(height[l]<height[r])l++;
            else r--;
        }
        return ans;
    }
    // 从高到低降，宽度逐渐增大
    // int maxArea(vector<int>& height) {
    //     int Maxidx[height.size()],Minidx[height.size()];
    //     memset(Maxidx,0xff,sizeof(Maxidx));
    //     memset(Minidx,0x3f,sizeof(Minidx));
    //     REP(i,height.size()){
    //         chmin(Minidx[height[i]],int(i));
    //         chmax(Maxidx[height[i]],int(i));
    //     }
    //     set<int,greater<int>>S(ALL(height));
    //     int ans=0,l=100000,r=0;
    //     for(int a:S){
    //         chmin(l,Minidx[a]);
    //         chmax(r,Maxidx[a]);
    //         chmax(ans,a*max(0,r-l));
    //     }
    //     return ans;
    // }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi height{1,8,6,2,5,4,8,3,7};
    auto ans=sol.maxArea(height);
    DBG(ans);

    system("pause");
    return 0;
}
