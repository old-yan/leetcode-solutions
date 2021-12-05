#include "utils.h"

class Solution {
public:
    //枚举 100~999 的所有三位数偶数，检查可行性
    vector<int> findEvenNumbers(vector<int>& digits) {
        // cnt 数组保存 0~9 的数量
        int cnt[10]={0};
        for(int d:digits)cnt[d]++;
        vector<int>ans;
        for(int value=100;value<1000;value+=2){
            int a=value/100;
            int b=value/10%10;
            int c=value%10;
            cnt[a]--,cnt[b]--,cnt[c]--;
            if(*min_element(cnt,cnt+10)>=0){
                ans.push_back(value);
            }
            cnt[a]++,cnt[b]++,cnt[c]++;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<int>digits{2,2,8,8,2};
    auto ans=sol.findEvenNumbers(digits);
    DBGV(ans);

    system("pause");
    return 0;
}