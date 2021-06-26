#include "utils.h"

class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        for(int i=1;;i++){
            int j=n-i;
            string a=i2s(i);
            string b=i2s(j);
            if(int(a.find('0'))<0&&int(b.find('0'))<0)return {i,j};
        }
        return {};
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=1895;
    auto ans=sol.getNoZeroIntegers(n);
    DBGV(ans);

    system("pause");
    return 0;
}
