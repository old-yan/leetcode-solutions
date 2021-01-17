#include "utils.h"

class Solution {
    //对墙位置的标注
    bool iswall[8][8]={0};
    //每个位置上、下、左、右能走到的最远的边界，第一个维度0表示猫视角，1表示老鼠视角
    int left[2][8][8];
    int right[2][8][8];
    int up[2][8][8];
    int down[2][8][8];
    int m,n;
    //使用pos表示位置，可以解读成两个char，或者解读成一个合并的short
    union pos{
        unsigned char c[2];
        unsigned short d;
        bool operator==(const pos&other)const{
            return d==other.d;
        }
    };
    //使用state结构体表示状态，一个状态含有四个下标/两个位置
    //c[0]、c[1]表示猫的位置，c[2]、c[3]表示老鼠的位置
    //c[0]和c[1]可以结合成一个short数d[0], c[2]和c[3]可以结合成一个short数d[1]
    struct state{
        union{
            unsigned char c[4];
            pos d[2];
        };
    };
    #define MAXSTEP 100
    //cpos,mpos,fpos分别表示猫/老鼠/食物的位置
    pos cpos,mpos,fpos;
    //cur表示当前状态
    state cur;
    //dp数组用作记忆化，避免重复搜索
    int dp[2][8][8][8][8][MAXSTEP+1];
    int cat_dfs(state&e,int step){
        int&cur=dp[0][e.c[0]][e.c[1]][e.c[2]][e.c[3]][step];
        if(cur>=0)return cur;
        if(step==MAXSTEP)return cur=1;
        if(e.d[0]==fpos)return cur=1;
        if(e.d[1]==fpos)return cur=0;
        int old=e.c[0],start=up[0][e.c[0]][e.c[1]],end=down[0][e.c[0]][e.c[1]];
        for(e.c[0]=start;e.c[0]<=end;e.c[0]++){
            if(e.d[0]==e.d[1]){
                e.c[0]=old;
                return cur=1;
            }
            if(!iswall[e.c[0]][e.c[1]]&&!mouse_dfs(e,step+1)){
                e.c[0]=old;
                return cur=1;
            }
        }
        e.c[0]=old;
        old=e.c[1],start=left[0][e.c[0]][e.c[1]],end=right[0][e.c[0]][e.c[1]];
        for(e.c[1]=start;e.c[1]<=end;e.c[1]++){
            if(e.d[0]==e.d[1]){
                e.c[1]=old;
                return cur=1;
            }
            if(!iswall[e.c[0]][e.c[1]]&&!mouse_dfs(e,step+1)){
                e.c[1]=old;
                return cur=1;
            }
        }
        e.c[1]=old;
        return cur=0;
    }
    int mouse_dfs(state&e,int step){
        int&cur=dp[1][e.c[0]][e.c[1]][e.c[2]][e.c[3]][step];
        if(cur>=0)return cur;
        if(step==MAXSTEP)return cur=0;
        if(e.d[0]==fpos)return cur=0;
        if(e.d[1]==fpos)return cur=1;
        int old=e.c[2],start=up[1][e.c[2]][e.c[3]],end=down[1][e.c[2]][e.c[3]];
        for(e.c[2]=start;e.c[2]<=end;e.c[2]++){
            if(e.d[0]==e.d[1])continue;
            if(!iswall[e.c[2]][e.c[3]]&&!cat_dfs(e,step+1)){
                e.c[2]=old;
                return cur=1;
            }
        }
        e.c[2]=old;
        old=e.c[3],start=left[1][e.c[2]][e.c[3]],end=right[1][e.c[2]][e.c[3]];
        for(e.c[3]=start;e.c[3]<=end;e.c[3]++){
            if(e.d[0]==e.d[1])continue;
            if(!iswall[e.c[2]][e.c[3]]&&!cat_dfs(e,step+1)){
                e.c[3]=old;
                return cur=1;
            }
        }
        e.c[3]=old;
        return cur=0;
    }
public:
    bool canMouseWin(vector<string>& grid, int catJump, int mouseJump) {
        m=grid.size(),n=grid[0].size();
        //预处理，找出猫/老鼠/食物的位置
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='C'){
                    cpos.c[0]=i;
                    cpos.c[1]=j;
                }
                else if(grid[i][j]=='M'){
                    mpos.c[0]=i;
                    mpos.c[1]=j;
                }
                else if(grid[i][j]=='F'){
                    fpos.c[0]=i;
                    fpos.c[1]=j;
                }
                else if(grid[i][j]=='#')iswall[i][j]=1;
            }
        }
        cur.d[0]=cpos;
        cur.d[1]=mpos;
        //预处理，求得每个位置向上下左右四个方向最多能走到哪里
        for(int i=0;i<m;i++){//猫视角
            for(int j=0;j<n;j++){
                if(iswall[i][j])continue;
                int k;
                for(k=j;k-1>=0&&j-k+1<=catJump&&!iswall[i][k-1];k--);
                left[0][i][j]=k;
                for(k=j;k+1<n&&k+1-j<=catJump&&!iswall[i][k+1];k++);
                right[0][i][j]=k;
                for(k=i;k-1>=0&&i-k+1<=catJump&&!iswall[k-1][j];k--);
                up[0][i][j]=k;
                for(k=i;k+1<m&&k+1-i<=catJump&&!iswall[k+1][j];k++);
                down[0][i][j]=k;
            }
        }
        for(int i=0;i<m;i++){//老鼠视角
            for(int j=0;j<n;j++){
                if(iswall[i][j])continue;
                int k;
                for(k=j;k-1>=0&&j-k+1<=mouseJump&&!iswall[i][k-1];k--);
                left[1][i][j]=k;
                for(k=j;k+1<n&&k+1-j<=mouseJump&&!iswall[i][k+1];k++);
                right[1][i][j]=k;
                for(k=i;k-1>=0&&i-k+1<=mouseJump&&!iswall[k-1][j];k--);
                up[1][i][j]=k;
                for(k=i;k+1<m&&k+1-i<=mouseJump&&!iswall[k+1][j];k++);
                down[1][i][j]=k;
            }
        }
        //dp数组初始化为-1，以便接下来的记忆化搜索
        memset(dp,0xff,sizeof(dp));
        return mouse_dfs(cur,0);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<string>grid{
        "C...#",
        "...#F",
        "....#",
        "M...."
    };
    auto ans=sol.canMouseWin(grid,2,5);
    DBG(ans);

    system("pause");
    return 0;
}
