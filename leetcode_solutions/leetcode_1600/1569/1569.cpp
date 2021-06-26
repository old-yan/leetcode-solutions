#include "utils.h"

auto ct=combinationTable(1000,1000);
class Solution {
    int val[1000],lc[1000],rc[1000],root=-1,cnt=0;
    void build(vi&nums){
        memset(lc,0xff,sizeof(lc));
        memset(rc,0xff,sizeof(rc));
        for(int a:nums){
            int*cur=&root;
            while(*cur>=0){
                if(val[*cur]>a)cur=lc+*cur;
                else cur=rc+*cur;
            }
            *cur=cnt++;
            val[*cur]=a;
        }
    }
    pair<int,int> traverse(int cur){//人数，排列数
        if(cur<0)return {0,1};
        auto l=traverse(lc[cur]);
        auto r=traverse(rc[cur]);
        return {l.first+r.first+1,(ll)ct[l.first+r.first][l.first]*l.second%MOD*r.second%MOD};
    }
public:
    int numOfWays(vector<int>& nums) {
        build(nums);
        return traverse(root).second-1;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{1,2,3};
    auto ans=sol.numOfWays(nums);
    DBG(ans);

    system("pause");
    return 0;
}
