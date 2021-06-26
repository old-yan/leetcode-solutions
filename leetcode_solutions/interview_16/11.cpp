#include "utils.h"

class Solution {
public:
    vector<int> divingBoard(int shorter, int longer, int k) {
        if(!k)return {};
        if(shorter==longer){
            return {shorter*k};
        }
        else{
            vi ans;
            REP(i,k+1){
                ans.pb(i*longer+(k-i)*shorter);
            }
            return ans;
        }
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int shorter=1;
    int longer=2;
    int k=3;
    auto ans=sol.divingBoard(shorter,longer,k);
    DBG(ans);

    system("pause");
    return 0;
}
