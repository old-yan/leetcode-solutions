#include "utils.h"

class Solution {
public:
    //对原矩阵的每一行进行遍历，把石头向右侧囤积
    //然后再填充到ans矩阵的每一列里
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m=box.size(),n=box[0].size();
        for(auto&row:box){
            //用下标j来遍历，每次遍历一个被固定障碍物围住的区间
            for(int j=0;j<n;j++){
                //cnt采集区间内的石头
                int cnt=0;
                while(j<n&&row[j]!='*'){
                    if(row[j]=='#'){
                        cnt++;
                        row[j]='.';
                    }
                    j++;
                }
                //将石头囤积到刚刚遇到的障碍物左边
                FORR(k,j-1,j-cnt){
                    row[k]='#';
                }
            }
        }
        //旋转为ans矩阵
        vector<vector<char>> ans(n,vector<char>(m));
        REP(i,m)REP(j,n){
            ans[j][m-1-i]=box[i][j];
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<vector<char>>box={
        {'#','#','*','.','*','.'},
        {'#','#','#','*','.','.'},
        {'#','#','#','.','#','.'}
    };
    auto ans=sol.rotateTheBox(box);
    DBGVV(ans);

    system("pause");
    return 0;
}