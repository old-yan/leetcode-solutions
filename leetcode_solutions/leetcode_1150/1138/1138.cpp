#include "utils.h"

class Solution {
public:
    string alphabetBoardPath(string target) {
        pair<int,int>pos[26];
        REP(c,26){
            int i=c/5,j=c%5;
            pos[c]={i,j};
        }
        int i=0,j=0;
        string ans;
        for(char c:target){
            auto [ii,jj]=pos[c-'a'];
            while(ii<i){//上
                ans+="U";
                i--;
            }
            while(jj<j){//左
                ans+="L";
                j--;
            }
            while(ii>i){//下
                ans+="D";
                i++;
            }
            while(jj>j){//右
                ans+="R";
                j++;
            }
            ans+="!";
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string target="leet";
    auto ans=sol.alphabetBoardPath(target);
    DBG(ans);

    system("pause");
    return 0;
}
