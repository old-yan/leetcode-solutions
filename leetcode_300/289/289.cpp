#include "utils.h"

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m=board.size(),n=board[0].size();
        REP(i,m){
            REP(j,n){
                int count=0;
                for(int ii=i-1;ii<=i+1;ii++){
                    for(int jj=j-1;jj<=j+1;jj++){
                        if(ii>=0&&ii<m&&jj>=0&&jj<n&&(ii!=i||jj!=j)){
                            if(board[ii][jj]&1)count++;
                        }
                    }
                }
                if(board[i][j]&1){
                    if(count==2||count==3)board[i][j]|=2;
                }
                else{
                    if(count==3)board[i][j]|=2;
                }
            }
        }
        REP(i,m){
            REP(j,n){
                board[i][j]>>=1;
            }
        }
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi board{
        {0,1,0},
        {0,0,1},
        {1,1,1},
        {0,0,0}
    };
    sol.gameOfLife(board);
    DBGVV(board);

    system("pause");
    return 0;
}
