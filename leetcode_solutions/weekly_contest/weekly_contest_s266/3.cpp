#include "utils.h"

class Solution {
public:
    //本题类似力扣 875 题
    int minimizedMaximum(int n, vector<int>& quantities) {
        //写个函数 f(a) 表示如果最大值为 a，需要几家商店收货
        auto need_stores=[&](int a){
            long long need=0;
            for(int each:quantities){
                need+=each%a==0?each/a:each/a+1;
            }
            return need;
        };
        int low=1,high=100000;
        while(low<high){
            int mid=(low+high)/2;
            if(need_stores(mid)>n)low=mid+1;
            else high=mid;
        }
        return low;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=7;
    vector<int>quantities{15,10,10};
    auto ans=sol.minimizedMaximum(n,quantities);
    DBG(ans);

    system("pause");
    return 0;
}