#include "utils.h"

class Solution {
    vector<string> pieces;
    vector<vector<int>> positions;
    int n;
    vector<vector<pair<int,int>>>directions;
    //used [i][j][t] 表示坐标 (i,j) 在 t 时刻是否被占用
    bool used[8][8][8]={0};
    int ans=0;
    //dfs 参数 cur 表示现在开始考虑 cur 的行程
    void dfs(int cur){
        //当 cur == n 表示 [0,n-1] 行程都考虑完了而且无冲突
        if(cur==n)ans++;
        else{
            //获取初始位置，习惯上下标基于 0
            int i=positions[cur][0]-1,j=positions[cur][1]-1;
            for(auto [di,dj]:directions[cur]){
                //用 ii，jj 表示当前位置，t 表示当前时间
                int t=0,ii=i,jj=j;
                while(true){
                    t++,ii+=di,jj+=dj;
                    if(ii<0 or ii>=8 or jj<0 or jj>=8)break;
                    //考虑 (ii,jj) 能否作为最终停留点
                    //检查 (ii,jj) 此处，时刻 [t,7] 是否被占用
                    //  如果被占用，那么不能作为最终停留点
                    //  如果没被占用，那么可以作为最终停留点，占用之，dfs下一个棋子。记得 dfs 回来后要恢复原状
                    if(!count(used[ii][jj]+t,used[ii][jj]+8,true)){
                        for(int tt=t;tt<8;tt++)used[ii][jj][tt]=true;
                        dfs(cur+1);
                        for(int tt=t;tt<8;tt++)used[ii][jj][tt]=false;
                    }
                    //如果 di==dj==0 ，走一步和走多步是一个效果，所以执行完一圈就可以break
                    if(!di and !dj)break;
                    //如果 (ii,jj) 此处 时刻 t 被占用，说明有人拦路，就不往前走了
                    else if(used[ii][jj][t])break;
                    //否则，将 (ii,jj) 此处的时刻 t 占用，然后继续往前走，寻找下一个永居点
                    else{
                        used[ii][jj][t]=true;
                        continue;
                    }
                }
                //按照 (di,dj) 的方向探索完毕，将这条路上占用的点恢复原状
                while(--t)used[i+di*t][j+dj*t][t]=false;
            }
        }
    }
public:
    //本题一看就是枚举组合状态。由于C++没有python那么方便的 product，所以老老实实 dfs
    int countCombinations(vector<string>& pieces, vector<vector<int>>& positions) {
        this->pieces=pieces;
        this->positions=positions;
        this->n=pieces.size();
        for(int i=0;i<n;i++){
            //根据棋子名称，赋予其不同的移动方向
            if(pieces[i]=="queen")directions.push_back({{-1,-1},{-1,0},{-1,1},{0,-1},{0,0},{0,1},{1,-1},{1,0},{1,1}});
            else if(pieces[i]=="rook")directions.push_back({{0,0},{-1,0},{0,-1},{0,1},{1,0}});
            else directions.push_back({{0,0},{-1,-1},{1,-1},{1,1},{-1,1}});
        }
        //dfs
        dfs(0);
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<string>pieces{"queen","bishop"};
    vector<vector<int>>positions=makevvi("[[5,7],[3,4]]");
    auto ans=sol.countCombinations(pieces,positions);
    DBG(ans);

    system("paused");
    return 0;
}