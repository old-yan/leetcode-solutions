#include "utils.h"

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int cursor=0;
        vector<string>ans;
        FOR(i,1,n+1){
            if(cursor==target.size())break;
            if(target[cursor]!=i){
                ans.pb("Push");
                ans.pb("Pop");
            }
            else{
                ans.pb("Push");
                cursor++;
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi target{1,3};
    int n=3;
    auto ans=sol.buildArray(target,n);
    DBGV(ans);

    system("pause");
    return 0;
}
