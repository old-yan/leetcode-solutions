#include "utils.h"

class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        int cnt[10001]={0};
        for(int a:deck)cnt[a]++;
        int _gcd=0;
        REP(i,10001){
            if(cnt[i]){
                _gcd=gcd(_gcd,cnt[i]);
            }
        }
        return _gcd>1;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi deck{1,2,3,4,4,3,2,1};
    auto ans=sol.hasGroupsSizeX(deck);
    DBG(ans);

    system("pause");
    return 0;
}
