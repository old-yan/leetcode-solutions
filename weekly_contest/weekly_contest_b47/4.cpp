#include "SegTree.h"
#include "utils.h"

class Solution {
    //邻接表（且只保存编号比自己大的邻居）
    vi adj[20000];
    //度数表
    int deg[20000]={0};
    //邻接矩阵占用空间太大，用不了，所以用哈希表存储矩阵中的非零点
    //维护点i与点j之间的边数k的方法是：M[i*50000+j]=k
    //（默认i<j）
    unordered_map<long,int>M;
public:
    vector<int> countPairs(int n, vector<vector<int>>& edges, vector<int>& queries) {
        vi ans;
        for(auto&edge:edges){
            //习惯上结点编号为从0到n-1
            int i=edge[0]-1,j=edge[1]-1;
            if(i>j)swap(i,j);
            //维护度数
            deg[i]++;
            deg[j]++;
            //维护邻接表，注意可能有重复边，所以只在第一次建边时放入邻接表
            if(!M[i*50000+j])adj[i].pb(j);
            M[i*50000+j]++;
        }
        //根据获取的度数表，可知最大度数（度数范围），并获取度数分布
        int maxdeg=*max_element(deg,deg+n);
        vi degmap(maxdeg+1,0);
        for(int i=0;i<n;i++)degmap[deg[i]]++;
        //枚举查询标准q
        for(int q:queries){
            int res=0;
            //按照度数分布，建立线段树，方便查询某个度数范围内的点的数量
            SegTree<int>T(degmap,0,[](int x,int y){return x+y;});
            for(int i=0;i<n;i++){
                //将自己的度数从度数分布里去除，因为自己不能充当自己的配对
                T.step_back(deg[i]);
                //累加的范围要求：目标度数加上deg[i]要比q大
                res+=T(q+1-deg[i],maxdeg);
                for(int a:adj[i]){
                    //如果i,a相邻，deg[i]+deg[a]>q但是去掉重复计算的边后就小于q了，那就res--，这一对不算
                    if(deg[i]+deg[a]>q&&deg[i]+deg[a]-M[i*50000+a]<=q)res--;
                }
            }
            ans.pb(res);
        }
        return ans;
    }
};


int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=6;
    vvi edges=makevvi("[[5,2],[3,5],[4,5],[1,5],[1,4],[3,5],[2,6],[6,4],[5,6],[4,6],[6,2],[2,6],[5,4],[6,1],[6,1],[2,5],[1,3],[1,3],[4,5]]");
    vi queiries{9};
    auto ans=sol.countPairs(n,edges,queiries);
    DBGV(ans);

    system("pause");
    return 0;
}
