#include "utils.h"

class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int num_wanted, int use_limit) {
        int n=values.size();
        int idx[n];
        iota(idx,idx+n,0);
        sort(idx,idx+n,[&](int x,int y){return values[x]>values[y];});
        int cnt[20001]={0},ans=0,used=0;
        for(int a:idx){
            int val=values[a],lab=labels[a];
            if(cnt[lab]<use_limit){
                cnt[lab]++;
                ans+=val;
                if(++used==num_wanted)break;
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi values{5,4,3,2,1};
    vi labels{1,1,2,2,3};
    int num_wanted=3;
    int use_limit=1;
    auto ans=sol.largestValsFromLabels(values,labels,num_wanted,use_limit);
    DBG(ans);

    system("pause");
    return 0;
}
