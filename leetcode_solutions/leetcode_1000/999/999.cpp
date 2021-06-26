#include "utils.h"

class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int Rr,Rc;
        int m=8,n=8;
        REP(i,m){
            REP(j,n){
                if(board[i][j]=='R'){
                    Rr=i;
                    Rc=j;
                }
            }
        }
        int ans=0;
        REP(k,4){
            int ii=Rr+di[k],jj=Rc+dj[k];
            while(VALID&&board[ii][jj]=='.'){
                ii+=di[k];
                jj+=dj[k];
            };
            if(VALID&&board[ii][jj]=='p')ans++;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<vector<char>>board{
        {'.','.','.','.','.','.','.','.'},
        {'.','.','.','p','.','.','.','.'},
        {'.','.','.','R','.','.','.','p'},
        {'.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.'},
        {'.','.','.','p','.','.','.','.'},
        {'.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.'}
    };
    auto ans=sol.numRookCaptures(board);
    DBG(ans);

    system("pause");
    return 0;
}
