#include "utils.h"

class Solution {
public:
    int maxAliveYear(vector<int>& birth, vector<int>& death) {
        int cnt[2100]={0};
        for(auto&b:birth)cnt[b]++;
        for(auto&d:death)cnt[d+1]--;
        partial_sum(cnt,cnt+2100,cnt);
        return max_element(cnt,cnt+2100)-cnt;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi birth{1900, 1901, 1950};
    vi death{1948, 1951, 2000};
    auto ans=sol.maxAliveYear(birth,death);
    DBG(ans);

    system("pause");
    return 0;
}
