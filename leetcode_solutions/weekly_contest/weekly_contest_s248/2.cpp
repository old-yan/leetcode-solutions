#include "utils.h"

class Solution {
public:
    //找出打怪数量小于到达城市数量的第一时刻
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n=dist.size();
        //用 num 数组统计每个时刻到达的怪物数量
        int num[100001]={0};
        for(int i=0;i<n;i++){
            int t=(dist[i]+speed[i]-1)/speed[i];
            num[t]++;
        }
        //求出前缀和
        partial_sum(num,num+100001,num);
        for(int i=0;i<=n;i++){
            //如果到达数量超过打死的数量，说明已经力不从心
            if(num[i]>=i+1)return i;
        }
        return n;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi dist{1,3,4};
    vi speed{1,1,1};
    auto ans=sol.eliminateMaximum(dist,speed);
    DBG(ans);

    system("pause");
    return 0;
}
