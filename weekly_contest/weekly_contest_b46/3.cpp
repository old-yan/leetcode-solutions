#include "utils.h"

class Solution {
    //triple结构体，用来表示图中的每个点位信息，i、j为坐标，k为高度
    struct triple{
        int i,j,k;
        triple(int _i,int _j,int _k):i(_i),j(_j),k(_k){}
    };
public:
    //本题使用多源BFS解决
    //可以证明不会有两个源bfs到交界时高度相差超过1。
    //因为队列中的点的高度是不断上升的，低点先入队，高点后入队，当目前处理从高度h到高度h+1的邻边时，所有高度小于h的点都已经出队，换句话说都已经不再裸露在外了。所以高度h+1的点不可能直接接触到高度小于h的点
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        queue<triple>Q;
        int m=isWater.size(),n=isWater[0].size();
        //默认每个点都可以很高，然后不断将其限制到低一些
        vvi ans(m,vi(n,INT_MAX));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                //将所有的水源送入队列
                if(isWater[i][j]){
                    ans[i][j]=0;
                    Q.emplace(i,j,0);
                }
            }
        }
        while(Q.size()){
            auto p=Q.front();
            Q.pop();
            //从四个方向找邻居
            REP(k,4){
                int ii=p.i+di[k],jj=p.j+dj[k];
                //如果邻居坐标合法，且还没有入队，那就将其入队
                if(VALID&&ans[ii][jj]==INT_MAX){
                    ans[ii][jj]=p.k+1;
                    Q.emplace(ii,jj,ans[ii][jj]);
                }
            }
            //找完邻居之后，p所代表的点一定已经被周围的点包裹起来了
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi isWater=makevvi("[[0,0,1],[1,0,0],[0,0,0]]");
    auto ans=sol.highestPeak(isWater);
    DBGVV(ans);

    system("pause");
    return 0;
}
