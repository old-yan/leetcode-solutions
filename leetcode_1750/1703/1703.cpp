#include "utils.h"

class Solution {
public:
    int minMoves(vector<int>& nums, int k) {
        vi ones;
        REP(i,nums.size())if(nums[i]==1)ones.pb(i);
        int l=0,m=(k-1)/2,r=k-1,cnt=0;
        REP(i,m){
            cnt+=(ones[i+1]-ones[i]-1)*(i+1);
        }
        FOR(i,m,r){
            cnt+=(ones[i+1]-ones[i]-1)*(r-i);
        }
        int ans=cnt;
        while(true){
            l++,m++,r++;
            if(r==ones.size())break;
            cnt-=ones[m-1]-ones[l-1]-m+l;
            cnt+=ones[r]-ones[m]-r+m;
            if(k%2==0){
                cnt-=ones[m]-ones[m-1]-1;
            }
            chmin(ans,cnt);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{1,0,0,1,0,1};
    int k=2;
    auto ans=sol.minMoves(nums,k);
    DBG(ans);

    system("pause");
    return 0;
}
