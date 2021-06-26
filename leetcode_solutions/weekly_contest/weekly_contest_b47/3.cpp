#include "utils.h"

class Solution {
public:
    int beautySum(string s) {
        int n=s.size();
        int ans=0;
        //确定好一个区间左端，然后尝试枚举区间右端
        for(int left=0;left<n;left++){
            int cnt[26]={0};
            cnt[s[left]-'a']=1;
            for(int right=left+1;right<n;right++){
                cnt[s[right]-'a']++;
                int Max=0,Min=INT_MAX;
                for(int k=0;k<26;k++){
                    if(cnt[k]){
                        chmax(Max,cnt[k]);
                        chmin(Min,cnt[k]);
                    }
                }
                //如果Max>Min，说明[left,right]区间内存在美丽值
                if(Max>Min){
                    ans+=Max-Min;
                }
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="aabcb";
    auto ans=sol.beautySum(s);
    DBG(ans);

    system("pause");
    return 0;
}
