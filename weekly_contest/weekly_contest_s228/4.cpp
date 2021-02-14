#include "utils.h"

class Solution {
public:
    //使用bitset作为描述邻接表的数据结构，b[i][j]=0，表示i与j不相连；b[i][j]=1，表示i与j相连
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        bitset<401>b[401];
        for(auto&edge:edges){
            int i=edge[0],j=edge[1];
            b[i].set(j);
            b[j].set(i);
        }
        int deg[401]={0};
        for(int i=1;i<=n;i++)deg[i]=b[i].count();
        int ans=INT_MAX;
        for(int first=1;first<n-1;first++){
            int second=first;
            while((second=b[first]._Find_next(second))<n){
                //join表示两个bitset的交集，join中为1的点，和first、second共同组成连通三元组
                auto join=b[first]&b[second];
                int third=second;
                while((third=join._Find_next(third))<=n){
                    ans=min(ans,deg[first]+deg[second]+deg[third]-6);
                }
            }
        }
        return short(ans);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=6;
    vvi edges{
        {1,2},{1,3},{3,2},{4,1},{5,2},{3,6}
    };
    auto ans=sol.minTrioDegree(n,edges);
    DBG(ans);

    system("pause");
    return 0;
}
