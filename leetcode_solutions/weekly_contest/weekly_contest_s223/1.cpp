#include "utils.h"

class Solution {
public:
    //异或运算规则：a^(a^b)=b
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int>res(encoded.size()+1);
        res[0]=first;
        for(int i=0;i<encoded.size();i++){
            res[i+1]=res[i]^encoded[i];
        }
        return res;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi encoded{6,2,7,3};
    int first=4;
    auto ans=sol.decode(encoded,first);
    DBGV(ans);

    system("pause");
    return 0;
}
