#include "utils.h"

class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string>ans;
        REP(i,12){
            REP(j,60){
                if(__builtin_popcount(i)+__builtin_popcount(j)==num){
                    char c[6];
                    sprintf(c,"%d:%02d",i,j);
                    ans.pb(c);
                }
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int num=4;
    auto ans=sol.readBinaryWatch(num);
    DBGV(ans);

    system("pause");
    return 0;
}
