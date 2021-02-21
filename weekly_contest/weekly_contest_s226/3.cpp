#include "SegTree.h"
#include "utils.h"

class Solution {
public:
    vector<bool> canEat(vector<int>&candiesCount, vector<vector<int>>& queries) {
        //利用线段树存储糖果分布情况
        SegTree<long> T(candiesCount,0,[](long x,long y){return x+y;});
        vector<bool>ans(queries.size());
        for(int i=0;i<queries.size();i++){
            long type=queries[i][0];
            long day=queries[i][1];
            long maxEat=queries[i][2];
            //earliest表示能吃到的最早的糖果类型的排名，那就是每天只吃一个
            long earliest=day;
            //如果earliest超出总和，说明早吃完了，没得吃了
            if(earliest>=T.data[1]){
                ans[i]=false;
                continue;
            }
            //latest表示能吃到的最迟的糖果类型的排名，那就是每天都吃maxEat个
            long latest=(day+1)*maxEat-1;
            //如果latest超出总和，将latest修改为总和-1
            if(latest>=T.data[1]){
                latest=T.data[1]-1;
            }
            int earliest_type=T.find_nth(earliest);
            int latest_type=T.find_nth(latest);
            if(type<earliest_type||type>latest_type)ans[i]=false;
            else ans[i]=true;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi can{13,45,31,29,13,20,11,33,18,13,10,39,43,36,5,38,27,38,10,33,46,17,20,28,41,29,3,35,38,46,32,7,37,5,27,15,46,9,11,37,47,44,48,34,37,12,3,37,29,25,7,34,45,23,17,10,46,5,37,34,5,45,5};
    vvi qu{
        {13,4,91}
    };
    auto ans=sol.canEat(can,qu);
    DBGV(ans);

    system("pause");
    return 0;
}
