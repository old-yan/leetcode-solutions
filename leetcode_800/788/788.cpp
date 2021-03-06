#include "utils.h"

const int type[10]={0,0,1,-1,-1,1,1,-1,0,1};
const int good_cnt[10]={0,0,1,1,1,2,3,3,3,4};
const int normal_cnt[10]={1,2,2,2,2,2,2,2,3,3};

class Solution {
    int judge(int val){
        int cnt=0;
        while(val){
            if(type[val%10]==-1)return -1;
            else if(type[val%10]==1)cnt++;
            val/=10;
        }
        if(cnt)return 1;
        else return 0;
    }
    pair<int,int>fun(int n){
        if(n<0)return {0,0};
        auto p=fun(n/10-1);
        p={p.first*7+p.second*4,p.second*3};
        int prefix=judge(n/10);
        if(prefix==1){
            p.first+=good_cnt[n%10]+normal_cnt[n%10];
        }
        else if(prefix==0){
            p.first+=good_cnt[n%10];
            p.second+=normal_cnt[n%10];
        }
        return p;
    }
public:
    int rotatedDigits(int N) {
        return fun(N).first;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int N=857;
    auto ans=sol.rotatedDigits(N);
    DBG(ans);

    system("pause");
    return 0;
}
