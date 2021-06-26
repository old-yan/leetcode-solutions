#include "utils.h"

class Solution {
public:
    int reverseBits(int num) {
        bitset<32>b(num);
        int pre[33]={0},post[33]={0};
        REP(i,32){
            pre[i+1]=b[i]?pre[i]+1:0;
        }
        REPR(i,31){
            post[i]=b[i]?post[i+1]+1:0;
        }
        int ans=0;
        for(int i=0;i<32;i++){
            chmax(ans,pre[i]+1+post[i+1]);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int num=1775;
    auto ans=sol.reverseBits(num);
    DBG(ans);

    system("pause");
    return 0;
}
