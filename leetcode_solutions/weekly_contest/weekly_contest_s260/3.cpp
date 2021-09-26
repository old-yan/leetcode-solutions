#include "utils.h"

class Solution {
public:
    //模拟就可以了，虽然时间复杂度有点大，但是很难卡满
    bool placeWordInCrossword(vector<vector<char>>& board, string word) {
        int m=board.size(),n=board[0].size(),l=word.size();
        //先逐行检查
        for(int i=0;i<m;i++){
            for(int j=0;j+l<=n;j++){
                //尝试把word放到board[i][j~j+l-1]
                if(j-1>=0){
                    char prev=board[i][j-1];
                    if(prev!='#')continue;
                }
                if(j+l<n){
                    char next=board[i][j+l];
                    if(next!='#')continue;
                }
                bool flag=true;
                //检查每个位置要么是空格，要么和word匹配
                for(int k=j;k<j+l;k++){
                    char cur=board[i][k];
                    if(isspace(cur) or cur==word[k-j])continue;
                    flag=false;break;
                }
                if(flag)return true;
                flag=true;
                //反向再来一次
                for(int k=j+l-1;k>=j;k--){
                    char cur=board[i][k];
                    if(isspace(cur) or cur==word[j+l-1-k])continue;
                    flag=false;break;
                }
                if(flag)return true;
            }
        }
        //把上面的代码抄一遍，逐列检查
        for(int j=0;j<n;j++){
            for(int i=0;i+l<=m;i++){
                if(i-1>=0){
                    char prev=board[i-1][j];
                    if(prev!='#')continue;
                }
                if(i+l<m){
                    char next=board[i+l][j];
                    if(next!='#')continue;
                }
                bool flag=true;
                for(int k=i;k<i+l;k++){
                    char cur=board[k][j];
                    if(isspace(cur) or cur==word[k-i])continue;
                    flag=false;break;
                }
                if(flag)return true;
                flag=true;
                for(int k=i+l-1;k>=i;k--){
                    char cur=board[k][j];
                    if(isspace(cur) or cur==word[i+l-1-k])continue;
                    flag=false;break;
                }
                if(flag)return true;
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
        {'#', ' ', '#'},
        {' ', ' ', '#'},
        {'#', 'c', ' '}
    };
    string word="abc";
    auto ans=sol.placeWordInCrossword(board,word);
    DBG(ans);

    system("pause");
    return 0;
}