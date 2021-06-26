#include "utils.h"

class Solution {
    int Min(vi&stones){
        int n=stones.size();
        int ans=n;
        for(int i=0,j=0;i<n;i++){
            if(stones.back()<stones[i]+n-1)break;
            while(j<n&&stones[j]<=stones[i]+n-1)j++;
            if(stones[j-1]<stones[i]+n-1&&!i)chmin(ans,n-j+i+1);
            else chmin(ans,n-j+i);
        }
        return ans;
    }
    int Max(vi&stones){
        int n=stones.size();
        if(n<=2)return 0;
        else return max(stones.back()-stones[1]-n+2,stones[n-2]-stones[0]-n+2);
    }
public:
    vector<int> numMovesStonesII(vector<int>& stones) {
        sort(ALL(stones));
        return {Min(stones),Max(stones)};
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi stones{100,101,104,102,103};
    auto ans=sol.numMovesStonesII(stones);
    DBGV(ans);

    system("pause");
    return 0;
}
