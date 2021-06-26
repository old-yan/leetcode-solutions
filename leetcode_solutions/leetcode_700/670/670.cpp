#include "utils.h"

class Solution {
public:
    int maximumSwap(int num) {
        string s=i2s(num);
        REP(i,s.size()){
            char maxC=0;
            FOR(j,i+1,s.size()){
                chmax(maxC,s[j]);
            }
            if(maxC>s[i]){
                int pos=s.find_last_of(maxC);
                swap(s[i],s[pos]);
                break;
            }
        }
        return s2i(s);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int num=2736;
    auto ans=sol.maximumSwap(num);
    DBG(ans);

    system("pause");
    return 0;
}
