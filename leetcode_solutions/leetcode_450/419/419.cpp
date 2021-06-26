#include "utils.h"

class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int ans=0;
        REP(i,board.size()){
            REP(j,board[0].size()){
                if(board[i][j]=='.')continue;
                if((i&&board[i-1][j]=='X')||(j&&board[i][j-1]=='X'))continue;
                ans++;
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<vector<char>>board{
        {'X','.','.','X'},
        {'.','.','.','X'},
        {'.','.','.','X'}
    };
    auto ans=sol.countBattleships(board);
    DBG(ans);

    system("pause");
    return 0;
}
