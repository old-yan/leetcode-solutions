#include "utils.h"

class Solution {
    struct{
        int cnt[26]={0},unique=0;
        void add(int c){
            if(cnt[c]==1)unique--;
            cnt[c]++;
            if(cnt[c]==1)unique++;
        }
        void remove(int c){
            if(cnt[c]==1)unique--;
            cnt[c]--;
            if(cnt[c]==1)unique++;
        }
    }counter;
public:
    //本题直接暴力枚举所有的长度为3的子串可以过，但是常数就得带个3
    //考虑常数更低的做法，就是用一个结构体，在添加/删除字符的时候，维护“唯一字符”的数量
    //这样，即使问题问的是长度为4、5、6...的问题，也是一样地快
    int countGoodSubstrings(string s) {
        int n=s.size();
        if(n<3)return 0;
        int ans=0;
        for(int left=0,right=0;left<s.size()-2;left++){
            while(right<left+3)
                counter.add(s[right++]-'a');
            if(counter.unique==3)ans++;
            counter.remove(s[left]-'a');
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="aababcabc";
    auto ans=sol.countGoodSubstrings(s);
    DBG(ans);

    system("pause");
    return 0;
}
