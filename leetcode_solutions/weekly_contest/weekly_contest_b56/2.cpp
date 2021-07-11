#include "utils.h"

class Solution {
public:
    //从入口进行bfs，记得把走过的地方标记为墙壁，避免重复遍历
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m=maze.size(),n=maze[0].size();
        queue<tuple<int,int,int>>Q;
        maze[entrance[0]][entrance[1]]='+';
        Q.emplace(entrance[0],entrance[1],0);
        while(Q.size()){
            auto [i,j,d]=Q.front();
            Q.pop();
            REP(k,4){
                int ii=i+di[k],jj=j+dj[k];
                //如果邻居的坐标不合法，说明 [i,j] 已经处于矩阵边缘
                if(!VALID){
                    if(i!=entrance[0]||j!=entrance[1])return d;
                    else continue;
                }
                else if(maze[ii][jj]=='.'){
                    maze[ii][jj]='+';
                    Q.emplace(ii,jj,d+1);
                }
            }
        }
        return -1;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<vector<char>>maze={
        {"+","+",".","+"},
        {".",".",".","+"},
        {"+","+","+","."}
    };
    vi entrance{1,2};
    auto ans=sol.nearestExit(maze,entrance);
    DBG(ans);

    system("pause");
    return 0;
}
