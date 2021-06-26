#include "utils.h"

class Solution {
public:
    bool makesquare(vector<int>& nums) {
        bitset<1<<15>b;
        int sum[1<<15]={0};
        int n=nums.size();
        FOR(i,1,1<<n){
            if(__builtin_popcount(i)>1)sum[i]=sum[i-(i&(-i))]+sum[i&(-i)];
            else sum[i]=nums[__builtin_ctz(i&(-i))];
        }
        if(sum[(1<<n)-1]%4)return false;
        if(sum[(1<<n)-1]==0)return false;
        int edge=sum[(1<<n)-1]/4;
        REP(i,1<<n){
            if(sum[i]%edge==0){
                if(!sum[i]||sum[i]==edge)b.set(i);
                else{
                    for(int j=i-1;j>=(i/2);j=(j-1)&i){
                        if(b[j]&&b[i-j]){
                            b.set(i);
                            break;
                        }
                    }
                }
            }
        }
        return b[(1<<n)-1];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{1,1,2,2,2};
    auto ans=sol.makesquare(nums);
    DBG(ans);

    system("pause");
    return 0;
}
