#include "utils.h"

class Solution {
public:
    bool reorderedPowerOf2(int N) {
        string s=i2s(N);
        sort(ALL(s));
        for(int i=1;;i<<=1){
            string ss=i2s(i);
            if(ss.size()==s.size()){
                sort(ALL(ss));
                if(ss==s)return true;
            }
            else if(ss.size()>s.size())break;
        }
        return false;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int N=10;
    auto ans=sol.reorderedPowerOf2(N);
    DBG(ans);

    system("pause");
    return 0;
}
