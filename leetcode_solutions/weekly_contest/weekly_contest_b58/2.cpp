#include "utils.h"

class Solution {
    char opp(char c){
        if(c=='B')return 'W';
        else return 'B';
    }
public:
    //向八个方向延伸，试探
    //八个方向枚举不需要方向数组，只需要 横向 * 纵向都枚举[-1,1] ，把 di=dj=0 的这一种情况排除掉就可以了
    bool checkMove(vector<vector<char>>& board, int rMove, int cMove, char color) {
        int m=board.size(),n=board[0].size();
        FOR(di,-1,2){
            FOR(dj,-1,2)if(di||dj){
                //dif记录异色数量
                int ii=rMove,jj=cMove,dif=0;
                while(true){
                    ii+=di,jj+=dj;
                    if(VALID&&board[ii][jj]==opp(color))dif++;
                    else break;
                }
                //如果存在异色，且停在同色的地方，那么返回true
                if(dif&&VALID &&board[ii][jj]==color)return true;
            }
        }
        return false;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<vector<char>>board={
        {'.','.','.','B','.','.','.','.'},
        {'.','.','.','W','.','.','.','.'},
        {'.','.','.','W','.','.','.','.'},
        {'.','.','.','W','.','.','.','.'},
        {'W','B','B','.','W','W','W','B'},
        {'.','.','.','B','.','.','.','.'},
        {'.','.','.','B','.','.','.','.'},
        {'.','.','.','W','.','.','.','.'}
    };
    int rMove=4;
    int cMove=3;
    char color='B';
    auto ans=sol.checkMove(board,rMove,cMove,color);
    DBG(ans);

    system("pause");
    return 0;
}
