#include "utils.h"

class Solution {
public:
    bool judgeCircle(string moves) {
        int i=0,j=0;
        unordered_map<char,int>M{
            {'R',0},{'U',1},{'L',2},{'D',3}
        };
        for(char c:moves){
            i+=di[M[c]];
            j+=dj[M[c]];
        }
        return !i&&!j;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string moves="UDLR";
    auto ans=sol.judgeCircle(moves);
    DBG(ans);

    system("pause");
    return 0;
}
