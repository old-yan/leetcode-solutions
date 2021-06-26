#include "utils.h"

class Solution {
public:
    int game(vector<int>& guess, vector<int>& answer) {
        int ans=0;
        REP(i,3){
            ans+=guess[i]==answer[i];
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi guess{1,2,3};
    vi answer{1,2,3};
    auto ans=sol.game(guess,answer);
    DBG(ans);

    system("pause");
    return 0;
}
