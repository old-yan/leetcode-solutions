#include "utils.h"

bool dp[200][200][16];
bool used[200][200];
class Solution {
    int m,n,l;
    bool check(int i,int j,int cur){
        if(used[i][j]||!dp[i][j][cur])return false;
        if(cur==l-1)return true;
        used[i][j]=true;
        REP(k,4){
            int ii=i+di[k],jj=j+dj[k];
            if(VALID&&check(ii,jj,cur+1)){
                return true;
            }
        }
        return used[i][j]=false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        m=board.size(),n=board[0].size(),l=word.size();
        memset(dp,0,sizeof(dp));
        REP(i,m)REP(j,n)dp[i][j][l]=true;
        REPR(cur,l-1){
            REP(i,m)REP(j,n)if(board[i][j]==word[cur]){
                if(cur==l-1)dp[i][j][cur]=true;
                else{
                    REP(k,4){
                        int ii=i+di[k],jj=j+dj[k];
                        if(VALID&&dp[ii][jj][cur+1]){
                            dp[i][j][cur]=true;
                            break;
                        }
                    }
                }
            }
        }
        memset(used,0,sizeof(used));
        REP(i,m)REP(j,n){
            if(check(i,j,0))return true;
        }
        return false;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<vector<char>>board{
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };
    string word="ABCB";
    auto ans=sol.exist(board,word);
    DBG(ans);

    system("pause");
    return 0;
}
