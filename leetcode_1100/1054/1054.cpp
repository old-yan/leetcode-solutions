#include "utils.h"

class Solution {
    int cnt[10001]={0};
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        for(int a:barcodes)cnt[a]++;
        sort(ALL(barcodes),[&](int x,int y){return cnt[x]>cnt[y]||(cnt[x]==cnt[y]&&x>y);});
        vi ans(barcodes.size());
        int cursor=0;
        for(int a:barcodes){
            ans[cursor]=a;
            cursor+=2;
            if(cursor>=ans.size())cursor=1;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi barcodes{1,1,1,1,2,2,3,3};
    auto ans=sol.rearrangeBarcodes(barcodes);
    DBGV(ans);

    system("pause");
    return 0;
}
