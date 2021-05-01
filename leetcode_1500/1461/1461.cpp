#include "utils.h"

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(s.size()<k)return false;
        bitset<1<<20>b;
        for(int left=0,right=0,val=0;right<s.size();left++){
            while(right<left+k)val=val*2+(s[right++]-'0');
            b.set(val);
            val%=(1<<(k-1));
        }
        return b.count()==(1<<k);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="00110110";
    int k=2;
    auto ans=sol.hasAllCodes(s,k);
    DBG(ans);

    system("pause");
    return 0;
}
