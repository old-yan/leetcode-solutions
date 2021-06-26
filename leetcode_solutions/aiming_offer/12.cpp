#include "utils.h"

bool used[200][200];
class Solution {
    int m,n,l;
    bool check(int i,int j,int cur,vector<vector<char>>& board, string&word){
        if(used[i][j]||word[cur]!=board[i][j])return false;
        if(cur==l-1)return true;
        used[i][j]=true;
        REP(k,4){
            int ii=i+di[k],jj=j+dj[k];
            if(VALID&&check(ii,jj,cur+1,board,word)){
                return true;
            }
        }
        return used[i][j]=false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        m=board.size(),n=board[0].size(),l=word.size();
        memset(used,0,sizeof(used));
        REP(i,m)REP(j,n){
            if(check(i,j,0,board,word))return true;
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
    string word="ABCCED";
    auto ans=sol.exist(board,word);
    DBG(ans);

    system("pause");
    return 0;
}
