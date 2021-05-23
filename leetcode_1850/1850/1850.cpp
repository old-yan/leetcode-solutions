#include "utils.h"

class Solution {
public:
    int getMinSwaps(string num, int k) {
        string copy=num;
        while(k--){
            next_permutation(ALL(copy));
        }
        int ans=0;
        REP(i,copy.size()){
            int j=num.find(copy[i],i);
            ans+=j-i;
            memmove(&num[i+1],&num[i],j-i);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string num="5489355142";
    int k=4;
    auto ans=sol.getMinSwaps(num,k);
    DBG(ans);

    system("pause");
    return 0;
}
