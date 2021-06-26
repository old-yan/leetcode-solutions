#include "utils.h"

class Solution {
public:
    int expectNumber(vector<int>& scores) {
        sort(ALL(scores));
        int ans=0;
        for(int i=0,j;i<scores.size();i=j){
            for(j=i+1;j<scores.size()&&scores[j]==scores[i];j++);
            ans++;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi scores{1,2,3};
    auto ans=sol.expectNumber(scores);
    DBG(ans);

    system("pause");
    return 0;
}
