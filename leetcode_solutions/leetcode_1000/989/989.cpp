#include "utils.h"

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        reverse(ALL(num));
        num[0]+=k;
        for(int i=0;i<num.size();i++){
            if(num[i]>=10){
                if(i+1==num.size()){
                    num.pb(0);
                }
                num[i+1]+=num[i]/10;
                num[i]%=10;
            }
        }
        reverse(ALL(num));
        return num;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi num{1,2,0,0};
    int k=34;
    auto ans=sol.addToArrayForm(num,k);
    DBGV(ans);

    system("pause");
    return 0;
}
