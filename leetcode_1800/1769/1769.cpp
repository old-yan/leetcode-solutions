#include "utils.h"

class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n=boxes.size();
        vi ans(n,0);
        int left=0,right=0;
        FOR(i,1,n)if(boxes[i]=='1'){
            ans[0]+=i;
            right++;
        }
        FOR(i,1,n){
            left+=boxes[i-1]=='1';
            ans[i]=ans[i-1]+left-right;
            right-=boxes[i]=='1';
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string boxes="110";
    auto ans=sol.minOperations(boxes);
    DBGV(ans);

    system("pause");
    return 0;
}
