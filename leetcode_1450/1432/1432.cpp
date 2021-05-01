#include "utils.h"

class Solution {
public:
    int maxDiff(int num) {
        string s=i2s(num);
        int Min=INT_MAX,Max=INT_MIN;
        REP(i,10){
            if(int(s.find('0'+i))<0)continue;
            REP(j,10){
                if(s[0]=='0'+i&&!j)continue;
                string ss=s;
                for(char&c:ss)if(c=='0'+i)c='0'+j;
                int val=s2i(ss);
                chmax(Max,val);
                chmin(Min,val);
            }
        }
        return Max-Min;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int num=555;
    auto ans=sol.maxDiff(num);
    DBG(ans);

    system("pause");
    return 0;
}
