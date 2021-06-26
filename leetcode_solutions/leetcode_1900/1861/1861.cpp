#include "utils.h"

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m=box.size(),n=box[0].size();
        vector<vector<char>>ans(n,vector<char>(m,'.'));
        REP(i,m){
            auto&row=box[i];
            int cursor=0;
            while(true){
                int stone=0;
                while(cursor<n&&row[cursor]!='*'){
                    stone+=row[cursor++]=='#';
                }
                FORR(j,cursor-1,cursor-stone){
                    ans[j][m-1-i]='#';
                }
                if(cursor<n)ans[cursor++][m-1-i]='*';
                else break;
            }
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
