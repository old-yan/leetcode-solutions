#include "utils.h"

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(ALL(g),greater<int>());
        sort(ALL(s),greater<int>());
        int ans=0;
        for(int i=0,j=0;i<g.size()&&j<s.size();i++){
            if(s[j]>=g[i]){
                ans++;
                j++;
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi g{1,2};
    vi s{1,2,3};
    auto ans=sol.findContentChildren(g,s);
    DBG(ans);

    system("pause");
    return 0;
}
