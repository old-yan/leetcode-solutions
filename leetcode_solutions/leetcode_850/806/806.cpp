#include "utils.h"

class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int currow=0,curlen=0;
        for(char c:s){
            curlen+=widths[c-'a'];
            if(curlen>100){
                currow++;
                curlen=widths[c-'a'];
            }
        }
        return {currow+1,curlen};
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi widths{10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10};
    string s="abcdefghijklmnopqrstuvwxyz";
    auto ans=sol.numberOfLines(widths,s);
    DBGV(ans);

    system("pause");
    return 0;
}
