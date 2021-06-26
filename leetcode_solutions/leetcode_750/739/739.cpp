#include "utils.h"

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<int>S;
        vi ans(T.size(),0);
        REP(i,T.size()){
            while(S.size()&&T[i]>T[S.top()]){
                ans[S.top()]=i-S.top();
                S.pop();
            }
            S.push(i);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi T{73, 74, 75, 71, 69, 72, 76, 73};
    auto ans=sol.dailyTemperatures(T);
    DBGV(ans);

    system("pause");
    return 0;
}
