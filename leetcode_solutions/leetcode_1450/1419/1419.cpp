#include "utils.h"

class Solution {
    int rnk[128]={0};
    void init(){
        rnk['c']=1;
        rnk['r']=2;
        rnk['o']=3;
        rnk['a']=4;
        rnk['k']=5;
    }
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        init();
        int cnt[6]={1000000,0,0,0,0,0};
        int ans=0;
        for(char c:croakOfFrogs){
            int r=rnk[c];
            if(!cnt[r-1])return -1;
            cnt[r-1]--;
            cnt[r]++;
            chmax(ans,accumulate(cnt+1,cnt+5,0));
        }
        if(accumulate(cnt+1,cnt+5,0))return -1;
        else return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string croakOfFrogs="croakcroak";
    auto ans=sol.minNumberOfFrogs(croakOfFrogs);
    DBG(ans);

    system("pause");
    return 0;
}
